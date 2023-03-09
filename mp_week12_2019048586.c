#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define LED PD4

void delay(unsigned long x)
{
	while(x--);
}

int main()
{
	DDRD |= (1<<LED);
	TCCR1B = (1<<CS10) | 1<<CS12);
	delay(100);
	TCNT1 = 0;

	while(1)
	{

		while((TIFR & (1<<0CF1AA)) == 0);
		PORTD ^= (1<<LED);
		TCNT1 = 0;
		TIFR |= (1<<0CF1A);
	}
}
