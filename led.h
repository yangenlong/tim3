#ifndef __LED_H 
#define __LED_H   
#include "sys.h" 
//LED �˿ڶ��� 
#define LED0 PBout(5) 
// PB5
#define LED1 PEout(5)
// PE5   
void LED_Init(void);
//��ʼ��  

 #endif