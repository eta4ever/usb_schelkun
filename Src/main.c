#define F_CPU 128000UL // 128 KHz INT RC OSC
#define MINUTE 60000 // минута в мс
#define OFFTIME 5000 // длительность выключенного состояния, мс
#define ONTIME 1 // длительность включенного состояния, минут

#include <avr/io.h>
#include <util/delay.h>

void on_delay(void)
// задержка включенного состояния
{
	for (uint16_t minutes=0; minutes<ONTIME; minutes++)
	{
		_delay_ms(MINUTE);
	}
}

void off_delay(void)
// задержка выключенного состояния
{
	_delay_ms(OFFTIME);
}

void power_on(void)
// включение питания
{
	PORTB |= (1<<PB3);
}

void power_off(void)
// выключение питания
{
	PORTB &= ~(1<<PB3);
}

void setup(void)
// настройка PB3 (pin2) как выхода и включение его
{
	DDRB |= (1<<PB3);
	power_on();
}

int main(void)
{
	setup(); // инициализация

	while(1)	// рабочий цикл
	{
		on_delay();
		power_off();
		off_delay();
		power_on();
	}

	return 0; // никогда
}
