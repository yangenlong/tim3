#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"


void KEY_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;//定义结构体变量  
 
 	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//使能PORTA时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//使能PORTE时钟

	//初始化  KEY0 1 2-->GPIOE.2 3 4    上拉输入
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3|GPIO_Pin_4;//KEY0-KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //PAE设置成上拉输入
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE3,4
	//因为按键都是低电平有效，故要设为上拉
	
	
	//初始化 WK_UP-->GPIOA.0	  下拉输入
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0

}
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY0按下
//2，KEY1按下
//3，KEY2按下 
//4，KEY3按下 WK_UP
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志  //记忆功能
	if(mode)key_up=1;  //支持连续按	去除这行则不支持  
	if(key_up&&(KEY0==0||KEY1==0||WK_UP==1))
	{
		delay_ms(10);//延时10ms 去抖动 
		key_up=0;//标记key已经按下
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
		//else if(KEY2==0)return KEY2_PRES;
		else if(WK_UP==1)return WKUP_PRES;
	}else if(KEY0==1&&KEY1==1&&WK_UP==0)key_up=1;//都没按 keyup置1 	    
 	return 0;// 无按键按下
}

