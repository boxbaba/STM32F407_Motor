//#ifndef _GUA_LIMIT_SWITCH_H_
//#define _GUA_LIMIT_SWITCH_H_
// 
///*********************�궨��************************/   
//#ifndef GUA_U8        
//typedef unsigned char GUA_U8;        
//#endif    
// 
//#ifndef GUA_8        
//typedef signed char GUA_8;        
//#endif      
//      
//#ifndef GUA_U16        
//typedef unsigned short GUA_U16;        
//#endif 
// 
//#ifndef GUA_16        
//typedef signed short GUA_16;        
//#endif         
//      
//#ifndef GUA_U32        
//typedef unsigned long GUA_U32;        
//#endif 
// 
//#ifndef GUA_32        
//typedef signed long GUA_32;       
//#endif
// 
//#ifndef GUA_U64    
//typedef unsigned long long GUA_U64;  
//#endif
// 
//#ifndef GUA_64    
//typedef signed long long GUA_64;  
//#endif
// 
////�ɶ�����λ����
//#define GUA_LIMIT_SWITCH_STATUS_UP                    0            //UP��λ����
//#define GUA_LIMIT_SWITCH_STATUS_DOWN                  1            //DWON��λ����
// 
////��λ���صĴ���״̬
//#define GUA_LIMIT_SWITCH_STATUS_TRIGGER               0            //��λ���ش���
//#define GUA_LIMIT_SWITCH_STATUS_IDLE                  1            //Dλ����û����
// 
///*********************�ⲿ��������************************/ 
//GUA_U8 GUA_Limit_Switch_Check_Pin(GUA_U8 nGUA_Limit_Switch_Status);  
//void GUA_Limit_Switch_Init(void);
// 
//#endif





#ifndef __EXTI_H
#define __EXIT_H	 
#include "sys.h"  	
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//�ⲿ�ж� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/4
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

#define TAGGLE 1
#define NORMAL 0

void EXTIX_Init(void);	//�ⲿ�жϳ�ʼ��		 
#endif

























