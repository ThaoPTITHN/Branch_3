#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
//cau hinh time2
void TIM2_Configure(){
	//Cap enable time CLOCK
	RCC -> APB1ENR  |= 0x01;
	//cau hinh bo chi tan so 
	TIM2 -> PSC      = 72 - 1;//he so chia la 71
	//ARR load gia tri 1000 vao thanh ghi ARR
	TIM2 -> ARR      = 0xFFFF;//65535 DEC 
	//cau hinh cho phep bo dem hoat dong va cau hinh cho Dem len
	TIM2 -> CR1      |= 0x01;
	//NGOAI ra co 1 su kien bit de lam sao RELOAD lai cac gia tri dat truoc
	TIM2 -> EGR      |= 0x01;
}
//cau hinh led pc13
void GPIO_Configure(){
	RCC -> APB2ENR  |= 0x10;
	GPIOC -> CRH    |= 0xFF0FFFFF;
	GPIOC -> CRH    |= 0x00300000;
}

void delay(int time){
	while(time){
		TIM2 -> CNT = 0;
		while((TIM2 -> CNT )< 1000){
		}
		time--;
	}
}
int main(){
	GPIO_Configure();
	TIM2_Configure();
	while(1){
		GPIOC -> ODR |= 0x2000;
		delay(10);
		GPIOC -> ODR &=~(0x2000);
		delay(10);
	}
}