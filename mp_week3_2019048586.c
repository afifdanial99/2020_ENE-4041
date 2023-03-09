#include<avr/io.h>

const char Font[17] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D, //0,1,2,3,4,5
		0x7D,0x07,0x7f,0x6F,0x77,0x7C, //6,7,8,9,A,B
		0x39,0x5E,0x&9,0x71,0x00 //C,D,E,F,NULL

void delay(unsigned long x)
{
	while(x--);
}

int main(void)
{
	unsigned char digit0, digit1,digit2,digit3;
	unsigned int count = 0;

	DDRB = 0xFF;
	DDRG = 0xFF;

	PORTB = 0x00;
	PORTG = 0xFF;

	while(1)
	{
		digit0=count / 1000;
		digit1=count /1000;
		digit2=count / 1000;
		digit3=count /1000;

		PORT=Font[digit0];
		PORT=Font[digit1];
		PORT=Font[digit2];
		PORT=Font[digit3];

		delay(1000);
		count++;

		if(count>999)
			break;
	}
}
		
