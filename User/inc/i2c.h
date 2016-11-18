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

#define OWNADRESS 0x1E//адрес контроллера
#define BUS_SCL		GPIO_Pin_6
#define BUS_SDA		GPIO_Pin_7
#define TW_BUS_FAIL        0x00//аппаратная ошибка шины
#define SB						0x01//отправлено условие старт
#define TW_START    	   0x08//отправлено условие старт
#define ReStart			   0x10//отправлен повторный старт
#define TW_MT_AD_ACK       0x18//ведущий послал адрес ведомого с битом для записи ведомый отозвался
#define TW_MT_AD_NACK      0x20//ведущий послал адрес ведомого с битом для записи ведомый не отозвался
#define TW_MT_DATA_ACK     0x28//ведущий послал данные и принял подтверждение 
#define TW_MT_DATA_NACK    0x30//ведущий послал данные и не принял подтверждение 
#define TW_MR_AD_ACK       0x40//ведущий послал адрес ведомого с битом для чтения ведомый отозвался
#define TW_MR_AD_NACK      0x48//ведущий послал адрес ведомого с битом для чтения ведомый не отозвался
#define TW_MR_DATA_ACK     0x50//ведущий принял данные и передал подтверждение
#define TW_MR_DATA_NACK    0x58//ведущий принял последний байт и передал NACK
/////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////ФУНКЦИИ//////////////////////////////////////////////////////
void I2C_init(void);// инициализация шины I2c просто задаем нужную скорость
void I2C_start(void);  // Генерация условия СТАРТ
void I2C_stop(void); // Генерация условия стоп
void I2C_tranciv_byte(uint8_t byte); // передача данных
uint8_t I2C_receiver_byte(void);// прием данных
uint8_t I2C_receiver_last_byte(void);// прием последнего байта
uint32_t get_status(void);//читаем статусный регистр
uint8_t MPU_I2C_R(uint8_t ra, uint8_t addrr);//протокол чтения данных из модуля MPU-6050
void MPU_I2C_W(uint8_t addrw, uint8_t ra, uint8_t data);//протокол записи
void i2c_send_adress(uint8_t Address, uint8_t I2C_Direction);// отправка адреса подчиненного устройства
/////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /*I2C_H_*/
