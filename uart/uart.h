/**
 * \file uart.h
 *
 * \brief UART library for Atmel 8bit microcontrollers
 *
 * \author Bernhard Rohloff <rohloff.bernhard@gmail.com>
 */

/*
 * map to stdout via
 *   stdout = uart_stdout();
 */

 #ifndef UART_H
 #define UART_H

 #include <stdint.h>
 #include <stdbool.h>

 #ifndef F_CPU
     #define F_CPU 8000000UL
 #endif

 #define BAUD 9600


 void uart_init(uint8_t config);

 void uart_putc(char c);

 char uart_getc(void);

 FILE* uart_stdout(void);

 #endif