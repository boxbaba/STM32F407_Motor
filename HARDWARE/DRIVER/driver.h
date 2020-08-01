#ifndef __DRIVER_H
#define __DRIVER_H
#include "sys.h"
#include "stdlib.h"	

#define DRIVER_DIR_LR   PGout(4) // ��ת����
#define DRIVER_OE_LR    PGout(3) // ʹ�ܽ� �͵�ƽ��Ч 

#define DRIVER_DIR_UD   PGout(2) // ��ת����
#define DRIVER_OE_UD    PGout(0) // ʹ�ܽ� �͵�ƽ��Ч 

#define RCR_VAL    255  //ÿ������RCR_VAL+1���Σ��ж�һ�Σ����ֵ��0~255�����ô�һЩ���Խ����ж�Ƶ��
#define RCR_VAL1    255  //ÿ������RCR_VAL+1���Σ��ж�һ�Σ����ֵ��0~255�����ô�һЩ���Խ����ж�Ƶ��

typedef enum
{
	CW = 1,//�ߵ�ƽ˳ʱ��
	CCW = 0,//�͵�ƽ��ʱ��
}DIR_Type;//���з���

extern long target_pos;//�з��ŷ���
extern long current_pos;//�з��ŷ���

void Driver_InitLR(void);//��������ʼ��
void Driver_InitUD(void);//��������ʼ��


void TIM8_OPM_RCR_InitLR(u16 arr,u16 psc);//TIM8_CH2 ���������+�ظ��������ܳ�ʼ��
void TIM8_OPM_RCR_InitUD(u16 arr,u16 psc);//TIM8_CH1 ���������+�ظ��������ܳ�ʼ��

void TIM8_StartupLR(u32 frequency);   //������ʱ��8
void TIM8_StartupUD(u32 frequency);

void Locate_RleLR(long num,u32 frequency,DIR_Type dir); //��Զ�λ����
void Locate_AbsLR(long num,u32 frequency);//���Զ�λ����

void Locate_RleUD(long num,u32 frequency,DIR_Type dir); //��Զ�λ����
void Locate_AbsUD(long num,u32 frequency);//���Զ�λ����

#endif


