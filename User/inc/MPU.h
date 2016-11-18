#ifndef MPU_H_
#define MPU_H_
#include "stm32f4xx.h"                  // Device header




#define MPU_6050_ADDRESS	 0xD0//
#define MPU_6050_ADDRESS_W 0xD0//адрес гироскопа в режиме записи
#define MPU_6050_ADDRESS_R 0xD1//адрес гироскопа в режиме чтения
#define PWR_MGMT_1         0x6B//адрес регистра Power Management его необходимо занулить
#define TEMP_OUT_H         0x41//адрес старшего байта реистра измерения температуры
#define TEMP_OUT_L         0x42//адрес младшего байта реистра измерения температуры
#define ACCEL_XOUT_H       0x3B//адрес старшего байта реистра измерения X акселерометра
#define ACCEL_XOUT_L       0x3C//адрес младшего байта реистра измерения X акселерометра
#define ACCEL_YOUT_H       0x3D//адрес старшего байта реистра измерения Y акселерометра
#define ACCEL_YOUT_L       0x3E//адрес младшего байта реистра измерения Y акселерометра
#define ACCEL_ZOUT_H       0x3F//адрес старшего байта реистра измерения Z акселерометра
#define ACCEL_ZOUT_L       0x40//адрес младшего байта реистра измерения Z акселерометра
#define GYRO_XOUT_H        0x43//адрес старшего байта реистра измерения X гироскопа
#define GYRO_XOUT_L        0x44//адрес младшего байта реистра измерения X гироскопа
#define GYRO_YOUT_H        0x45//адрес старшего байта реистра измерения Y гироскопа
#define GYRO_YOUT_L        0x46//адрес младшего байта реистра измерения Y гироскопа
#define GYRO_ZOUT_H        0x47//адрес старшего байта реистра измерения Z гироскопа
#define GYRO_ZOUT_L        0x48//адрес младшего байта реистра измерения Z гироскопа
#define XA_TEST			   0x0D//
#define YA_TEST			   0x0E//
#define ZA_TEST			   0x0F//
//////////////////////////////////////////////////////////////////////////////////////////
void MPU_init(void);//зануляем регистр управления питанием, без этого не читаются данные
uint8_t MPU_I2C_R(uint8_t ra, uint8_t addrr);//протокол чтения данных из модуля MPU-6050
void MPU_I2C_W(uint8_t addrw, uint8_t ra, uint8_t data);//протокол записи

#endif
