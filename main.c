#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 
//Tout（溢出时间）=（ARR+1)(PSC+1)/Tclk
//2s=(19999+1)(7199+1)/72000
//Tclk:TIM3 的输入时钟频率（单位为 Mhz ）。
//Tout:TIM3 溢出时间（单位为 us ）。
 int main(void)
 {		
 	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	 
	delay_init();	    	 //延时函数初始化	  
 	LED_Init();			     //LED端口初始化
	TIM3_Int_Init(19999,7199);//10Khz的计数频率，计数到20000为2s  
	 
   	while(1)
	{
		LED0=!LED0;
		delay_ms(200);		   
	}	 

 
}	 
 
