#include "sys.h"
#include "delay.h"  
#include "usart.h"  
#include "led.h"
#include "usmart.h"
#include "key.h"
#include "driver.h"
#include "exti.h"




int main(void)
{ 
	
	u8 i = 0;
	u8 j = 10;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);      //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	usmart_dev.init(84); 	//��ʼ��USMART			
	EXTIX_Init();

	Driver_InitUD();			//��������ʼ��
	TIM8_OPM_RCR_InitUD(999,168-1); //1MHz����Ƶ��  ������+�ظ�����ģʽ 
	
	
	while(1)
	{
		
		Locate_RleLR(400,500,CW);
		delay_ms(3000);
		Locate_RleUD(20000,20000,CW);
		delay_ms(5000);
		Locate_RleLR(400,500,CCW);
		delay_ms(3000);
		Locate_RleUD(30000,10000,CCW);
		delay_ms(5000);
	}
	

}
