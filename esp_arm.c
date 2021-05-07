#include "stm32f10x.h"                  // Device header
#include "stm32f10x_usart.h"            // Keil::Device:StdPeriph Drivers:USART
#include <stdio.h>
#include "esp_arm.h"

void gpioConfig(){
	//TX
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIOInitStructure);
   
	//RX
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIOInitStructure);
}
void uartConfig(int baud_rate){
   USART_InitTypeDef UARTInitStructure;
   
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
   
   UARTInitStructure.USART_BaudRate=baud_rate;
   UARTInitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
   UARTInitStructure.USART_Mode=USART_Mode_Tx | USART_Mode_Rx;
   UARTInitStructure.USART_Parity=USART_Parity_No;
   UARTInitStructure.USART_StopBits=USART_StopBits_1;
   UARTInitStructure.USART_WordLength=USART_WordLength_8b;
   
   USART_Init(USART1,&UARTInitStructure);
   USART_Cmd(USART1,ENABLE);
}
void uartTransmit(char *string){
	
   while(*string){
      while(!(USART1->SR & 0x00000040));
      USART_SendData(USART1,*string);
      *string++;

   }
}
void delay(uint32_t time ){

   while(time--);
   
}
void connectionTest(){
	sprintf(message,"%s\n",connectionMessage);
	uartTransmit(message);
	//If we can see OK on serial port, our ESP is working
}
void modeInfo(){
	sprintf(message,"%s\n",modeInfoMessage);
	uartTransmit(message);
}
void modeConfig(int mode){
	if(mode == 1){
		sprintf(message,"%s\n",modeChanging_STA_Message);
		uartTransmit(message);
	}
	else if(mode == 2){
		sprintf(message,"%s\n",modeChanging_AP_Message);
		uartTransmit(message);	
	}
	else if(mode == 3){
		sprintf(message,"%s\n",modeChanging_Both_APSTA_Message);
		uartTransmit(message);	
	}
}
void wifiConnection(){
	sprintf(message,"%s\n",wifiConnection_Message);
	uartTransmit(message);
}
void wifiDisconnect(){
	sprintf(message,"%s\n",wifiDisconnect_Message);
	uartTransmit(message);
}
void GetInfo_IP(){
	sprintf(message,"%s\n",IP_ConnectionInfo_Message);
	uartTransmit(message);
}


