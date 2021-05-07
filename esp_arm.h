#include "stm32f10x.h"                  // Device header
#include "stm32f10x_usart.h"            // Keil::Device:StdPeriph Drivers:USART
#include <stdio.h>

char message[20];
char connectionMessage[20] = "AT"
char modeInfoMessage[20] = "AT+CWMODE?"
char modeChanging_STA_Message[20] = "AT+CWMODE=1"
char modeChanging_AP_Message[20] = "AT+CWMODE=2"
char modeChanging_Both_APSTA_Message[20] = "AT+CWMODE=3"
char wifiConnection_Message[20] = "AT+CWJAP=\"wifi-adý\",\"wifi-sifresi\""
char IP_ConnectionInfo_Message[20] = "AT+CIFSR"
char wifiDisconnect_Message[20] = "AT+CWQAP"

void gpioConfig();
void uartConfig(int baud_rate);
void uartTransmit(char *string);
void delay(uint32_t time);
void connectionTest();
void modeInfo();
void modeConfig(int mode);
void wifiConnection();
void wifiDisconnect();
void GetInfo_IP();
