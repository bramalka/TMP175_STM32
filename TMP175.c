#include "TMP175.h"

I2C_HandleTypeDef i2ctmp;

void Tmp175_Init(I2C_HandleTypeDef *i2chandletmp) {
	i2ctmp = *i2chandletmp;
}

void Read_TempCelsius(uint8_t address,float *receive_buffer) {
	uint8_t write[1];
	write[0] = 0x00;
//	write[1] = 0x03;
	
	uint8_t buff[2];
	uint16_t TempSum;
	
	HAL_I2C_Master_Transmit(&i2ctmp, address, write, 1, 1);
	HAL_I2C_Master_Receive(&i2ctmp, address, buff, 2, 100);
	
	TempSum = (((buff[0] << 8) | buff[1]) >> 4);
	*receive_buffer = (TempSum * FTMP175_TEMP_AD_STEP);
}
