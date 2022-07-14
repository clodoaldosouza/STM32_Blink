/*
	Blink on GP11 using STM32F030C6T 
	KEIL 5 + STM32CubeMX 
*/

#include "stm32f10x.h"

void delay(uint32_t times);

void delay(uint32_t times){
	uint32_t i;
	for(i =0; i< times; i++);
}

int main(void){	
	RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
	GPIOB->CRH = 0x44443444;
	GPIOB->CRH |= GPIO_CRH_MODE11_0 | GPIO_CRH_MODE11_1; 
	GPIOB->CRH &= ~(GPIO_CRH_MODE11_0 | GPIO_CRH_MODE11_1);

	for (;;){		
		GPIOB->ODR |= 1<<11;
		delay(1000000);		
		GPIOB->ODR |= 0<<11;
		delay(1000000);
	}
}
