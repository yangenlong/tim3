#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 
//Tout�����ʱ�䣩=��ARR+1)(PSC+1)/Tclk
//2s=(19999+1)(7199+1)/72000
//Tclk:TIM3 ������ʱ��Ƶ�ʣ���λΪ Mhz ����
//Tout:TIM3 ���ʱ�䣨��λΪ us ����
 int main(void)
 {		
 	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	 
	delay_init();	    	 //��ʱ������ʼ��	  
 	LED_Init();			     //LED�˿ڳ�ʼ��
	TIM3_Int_Init(19999,7199);//10Khz�ļ���Ƶ�ʣ�������20000Ϊ2s  
	 
   	while(1)
	{
		LED0=!LED0;
		delay_ms(200);		   
	}	 

 
}	 
 
