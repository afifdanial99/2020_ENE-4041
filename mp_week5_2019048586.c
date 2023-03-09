#include <avr/io.h>

int main(void)
{
	unsigned char input_data;
	DDRA = 0x00;
	DDRB = 0xFF;

	while(1)
	{
	input_data = PINA;
	PORTB = input_data;
