#include "stm32f4xx.h"
#include "MPU.h"
#include "i2c.h"

void MPU_init(void)
{
		MPU_I2C_W(MPU_6050_ADDRESS_W,PWR_MGMT_1, 0x00);//зануляем регистр управления питанием, без этого не читаются данные
}

uint8_t MPU_I2C_R(uint8_t ra, uint8_t addrr)
{
	uint8_t data;
	I2C_start();//отправляем условие СТАРТ
	i2c_send_adress(addrr, I2C_Direction_Transmitter);//отправляем адрес модуля на запись
	I2C_tranciv_byte(ra);//отправляем адрес регистра откуда будем читать данные
	I2C_start();//отправляем повторный СТАРТ
	i2c_send_adress(addrr, I2C_Direction_Receiver);//отправляем адрес модуля на чтение
	data = I2C_receiver_last_byte();//читаем данные из регистра
	I2C_stop();//отправляем условие СТОП
	return data;
}

void MPU_I2C_W(uint8_t addrw, uint8_t ra, uint8_t data)
{
	I2C_start();//отправляем условие СТАРТ
	i2c_send_adress(addrw, I2C_Direction_Transmitter);//отправляем адрес модуля на запись
	I2C_tranciv_byte(ra);//отправляем адрес регистра куда будем записывать данные
	I2C_tranciv_byte(data);//записываем данные
	I2C_stop();//отправляем условие СТОП
}

