/*
+---------------------------------------------------------------+
| File    	     : I2C.h                                |
| Author  	 	 : Kopranych                                    |
| Git repository : |
| Mail   		 : kopranych@gmail.ru                           |
| Data    	     : 04/11/2016                                   |
| Device   		 : STM32F4xx                                    |
| Compiler 		 : MDK-ARM (Keil)                               |
| Project  		 : I2C                                   |
| Version  	   	 : 1.0  							            |
| Discription 	 :        |
+---------------------------------------------------------------+
*/

#ifndef I2C_H_
#define I2C_H_


#include "stm32f4xx.h"                  // Device header

#define OWNADRESS 0x1E//����� �����������
#define BUS_SCL		GPIO_Pin_6
#define BUS_SDA		GPIO_Pin_7
#define TW_BUS_FAIL        0x00//���������� ������ ����
#define SB						0x01//���������� ������� �����
#define TW_START    	   0x08//���������� ������� �����
#define ReStart			   0x10//��������� ��������� �����
#define TW_MT_AD_ACK       0x18//������� ������ ����� �������� � ����� ��� ������ ������� ���������
#define TW_MT_AD_NACK      0x20//������� ������ ����� �������� � ����� ��� ������ ������� �� ���������
#define TW_MT_DATA_ACK     0x28//������� ������ ������ � ������ ������������� 
#define TW_MT_DATA_NACK    0x30//������� ������ ������ � �� ������ ������������� 
#define TW_MR_AD_ACK       0x40//������� ������ ����� �������� � ����� ��� ������ ������� ���������
#define TW_MR_AD_NACK      0x48//������� ������ ����� �������� � ����� ��� ������ ������� �� ���������
#define TW_MR_DATA_ACK     0x50//������� ������ ������ � ������� �������������
#define TW_MR_DATA_NACK    0x58//������� ������ ��������� ���� � ������� NACK
/////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////�������//////////////////////////////////////////////////////
void I2C_init(void);// ������������� ���� I2c ������ ������ ������ ��������
void I2C_start(void);  // ��������� ������� �����
void I2C_stop(void); // ��������� ������� ����
void I2C_tranciv_byte(uint8_t byte); // �������� ������
uint8_t I2C_receiver_byte(void);// ����� ������
uint8_t I2C_receiver_last_byte(void);// ����� ���������� �����
uint32_t get_status(void);//������ ��������� �������
uint8_t MPU_I2C_R(uint8_t ra, uint8_t addrr);//�������� ������ ������ �� ������ MPU-6050
void MPU_I2C_W(uint8_t addrw, uint8_t ra, uint8_t data);//�������� ������
void i2c_send_adress(uint8_t Address, uint8_t I2C_Direction);// �������� ������ ������������ ����������
/////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /*I2C_H_*/
