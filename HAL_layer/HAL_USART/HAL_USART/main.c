/*
 * HAL_USART.c
 *
 * Created: 11/09/2018 20:51:15
 * Author : Mahmoud_saad
 */ 

//#include <avr/io.h>
#include "hal_USART.h"
	usart_t usart_1;
void usart_send()
{
	msa_u8 temp='M';
	usart_send_byte(&usart_1,&temp);
}
int main(void)
{
    /* Replace with your application code */

	usart_init(&usart_1,B_SENDER_N_RECEIVER,ONE_STP_BIT,NO_PARITY,EIGHT,POLLING_DRIVEN,FALLING_EDGE); 
    msa_u8 got_val;
	msa_u8 temp_val=' ';
	msa_u8 *arr_add=(msa_u8 *)"you gave me this =>";
	msa_u8 *arr_add2=(msa_u8 *)"put your val ";
	msa_u8 *got_arr;
	//usart_set_isr_TXC_callback(&usart_1,usart_send);
	msa_u8 arr[10];
	//usart_set_isr_TXC_callback(&usart_1,usart_send);
	while (1) 
    {
		
		usart_receive_arr(&usart_1,arr,10);
 		usart_send_arr(&usart_1,arr);
 		//usart_send_byte(&usart_1,(msa_u8 *)&val);
		usart_send_arr(&usart_1,arr_add2);		
		usart_receive_byte(&usart_1,&got_val);
		_delay_ms(500);
		usart_send_arr(&usart_1,arr_add);
		usart_send_byte(&usart_1,&got_val);
		usart_send_byte(&usart_1,&temp_val);
		//usart_receive_arr(&usart_1,got_arr);
		usart_send_arr(&usart_1,arr_add);
		usart_send_arr(&usart_1,got_arr);
    }
}

