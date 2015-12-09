#define F_CPU 128000UL // 128 KHz INT RC OSC
#define MINUTE 60000 // ������ � ��
#define OFFTIME 5000 // ������������ ������������ ���������, ��
#define ONTIME 1 // ������������ ����������� ���������, �����

#include <avr/io.h>
#include <util/delay.h>

void on_delay(void)
// �������� ����������� ���������
{
	for (uint16_t minutes=0; minutes<ONTIME; minutes++)
	{
		_delay_ms(MINUTE);
	}
}

void off_delay(void)
// �������� ������������ ���������
{
	_delay_ms(OFFTIME);
}

void power_on(void)
// ��������� �������
{
	PORTB |= (1<<PB3);
}

void power_off(void)
// ���������� �������
{
	PORTB &= ~(1<<PB3);
}

void setup(void)
// ��������� PB3 (pin2) ��� ������ � ��������� ���
{
	DDRB |= (1<<PB3);
	power_on();
}

int main(void)
{
	setup(); // �������������

	while(1)	// ������� ����
	{
		on_delay();
		power_off();
		off_delay();
		power_on();
	}

	return 0; // �������
}
