#include "stm32f4xx.h"

#define FTMP175_TEMP_AD_STEP		0.0625

//#define TMP175_ADDR	0x90
//#define TMP175_ADDR_1	0x92

void Tmp175_Init(I2C_HandleTypeDef *i2chandletmp);
void Read_TempCelsius(uint8_t address,float *receive_buffer);
