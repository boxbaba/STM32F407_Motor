#include "exti.h"
#include "delay.h" 
#include "led.h" 
#include "key.h"
#include "driver.h"
#include "sys.h"
#include "usart.h"


//�ⲿ�ж�0������� �ұߴ������ж�
void EXTI0_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line0) == 1)
  {
		printf("--------exit0-------------");
		Locate_RleLR(200,200,CW);
		
    EXTI_ClearITPendingBit(EXTI_Line0);
  }//���LINE0�ϵ��жϱ�־λ 
}


//�ⲿ�ж�1������� ��ߴ������ж�
void EXTI1_IRQHandler(void)
{
	 if(EXTI_GetITStatus(EXTI_Line1) == 1)
	  {
		printf("--------exit1-------------");
			Locate_RleLR(200,200,CW);
		
    EXTI_ClearITPendingBit(EXTI_Line1);
  }//���LINE1�ϵ��жϱ�־λ 
}


//�ⲿ�ж�2������� �·��������ж�
void EXTI2_IRQHandler(void)
{

	 if(EXTI_GetITStatus(EXTI_Line2) == 1)
	  {
			printf("--------exit2-------------");
		Locate_RleUD(10000,10000,CW);
		
    EXTI_ClearITPendingBit(EXTI_Line2);
  } //���LINE2�ϵ��жϱ�־λ  
}
//�ⲿ�ж�3������� �Ϸ��������ж�
void EXTI3_IRQHandler(void)
{

 if(EXTI_GetITStatus(EXTI_Line3) == 1)
	 {
		 printf("--------exit3-------------");
		Locate_RleUD(10000,10000,CW);
		
    EXTI_ClearITPendingBit(EXTI_Line3);
  }//���LINE3�ϵ��жϱ�־λ  
}



void EXTIX_Init(void)
{
	
	//PB0ʹ��Exit0���ж��ߣ�PG1ʹ��Exit1��PC2ʹ��Exit2��PA3ʹ��Exit3
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;
	

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOG|RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOA, ENABLE);//ʹ��GPIOB,GPIOG,GPIOC,GPIOAʱ��
 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//ʹ��SYSCFGʱ�ӣ��ж���Ҫʹ��AFIOʱ��)
	
	
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //PB0��ӦIO����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB0
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; //PG1��ӦIO����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ��GPIOG1
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //PC2��ӦIO����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC2
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; //PA3��ӦIO����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA3
	
 
 
 
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource0);//PB0 ���ӵ��ж���0
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOG, EXTI_PinSource1);//PG1 ���ӵ��ж���1
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource2);//PC2 ���ӵ��ж���2
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource3);//PA3 ���ӵ��ж���3
	
	//�����ж���
  EXTI_InitStructure.EXTI_Line = EXTI_Line0|EXTI_Line1|EXTI_Line2|EXTI_Line3;//LINE0
	
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж��¼�
	//��ʼ״̬Ϊ�͵�ƽ������⵽����ʱ��KEY0����ߵ�ƽ����ʱINT0��ͨ����Ϊ�͵�ƽ�������������������½���ʱ����
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; 
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//ʹ��LINE0
  EXTI_Init(&EXTI_InitStructure);//����
	
	
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;//PB0��Ӧ���ⲿ�ж�0
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//���������ȼ���ֻ��Ҫ��ƽת��ʱ�����жϼ���
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;//�ⲿ�ж�2
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//��ռ���ȼ�3
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;//�����ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����
	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;//�ⲿ�ж�3
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//��ռ���ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;//�����ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����
	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;//�ⲿ�ж�4
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//��ռ���ȼ�1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;//�����ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����
	   
}




