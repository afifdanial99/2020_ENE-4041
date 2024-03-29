#include <avr/io.h>
#define KEY_CTRL PORTE
#define RO 0x10

void delay(unisigned long x)
{
	while(x--);
}

unisigned char key_scan(void)
{
	unsigned char scan = 0;
	unsigned char key_control = 0;
	unsigned char input_data = 0;
	unsigned char key = 0;

	key_control = R0;

	for(scan=0;scan<4;scan++)
	{
		KEY_CTRL &= 0x0F;
		KEY_CTRL |= key_control;
		delay(1);
		input_data = PINF & 0x07;

		if(input_data != 0)
			key = (input_data>>1) + 1 + scan * 3;

		key_control <<= 1;


	}

	return key;

}


int main(void)
{
	unsigned char led = 0;
	unsigned shar key = 0;
	DDRF = 0x00;
	DDRE = 0xFF;
	DDRA = 0xFF;

	while(1)
	{
		key = key_scan();

		led = 0x01;

		if(key==0)
			led = 0x00;

		else if(key<9)
			led = led << (key-1);

		else if(key==9)
			led = 0x81;

		else if(key==10)
			led = 0x0F;
		
		else if(key==11)
			led = 0xFF;

		else if(key==12)
			led = 0xF0;

		PORTA = led;
	}
}
