
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"


#define CALCULATE_UBRR() F_CPU/(BAUD*16)-1


/*
 * map to stdout via
 *   stdout = uart_stdout();
 */


static int uart_putc(char c, FILE *stream);

static FILE uart_stdout = FDEV_SETUP_STREAM(uart_putc,
	                                        NULL,
	                                        FDEV_SETUP_WRITE);

void uart_init(uint8_t config)
{
	UBRR = CALCULATE_UBRR();
	UCR  =  config;
}

int uart_putc(char c, FILE *stream)
{
	while( !(USR & (1<<UDRE)) );
	UDR = c;
	return 0;
}

FILE* uart_stdout(void)
{
	return &uart_stdout;
}