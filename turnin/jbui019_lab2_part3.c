/*	Author: jbui019
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB  = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tmpB = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char availcnt = 0x00;
    /* Insert your solution below */
    while (1) {
	// Read Input from PINA
	tmpA = PINA & 0x03;
	
	// if PA) is 1, set PB1PB0 = 01, else = 10
	if(tmpA == 0x01){
		tmpB = (tmpB & 0xFC) | 0x01; //sets tmpB to bbbbbb01

	}
	else{
		tmpB = (tmpB & 0xFC) | 0x00;//sets tmpB to bbbbbb00
	}

	PORTB = tmpB;
	
	//Read input from PINA [3:0]
	tmpC = PINA & 0x0F;
		
	// if tmpC is filled with 4 spots
	if(tmpC == 0x0F){
		availcnt = 0x04;
	}
	else if(tmpC == 0x0E || tmpC == 0x0D || tmpC == 0x0B || tmpC == 0x07){
		availcnt = 0x03;
	}
	else if(tmpC == 0x0C || tmpC == 0x0A || tmpC == 0x09 || tmpC == 0x06 || tmpC == 0x05 		|| tmpC == 0x03 ){
		availcnt = 0x02;
	}
	else{
		availcnt = 0x01;
	}

	if(availcnt == 0x04){
		PORTC = 0x80 | availcnt;
	}
	else{ 
		PORTC = availcnt;
	}
	}	
    return 1;
}

