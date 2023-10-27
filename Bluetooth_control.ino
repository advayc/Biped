#include <avr/io.h>
#include <avr/interrupt.h>
#include <LCD.h>
#define clearbit(x,y)(x &=~y)
#define setbit(x,y) (x |= y)
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
LCD lcd;

chat data;
int a = 1;
int count = 0;
int right_hip, count_angle, right_foot, count_angle1,
left_hip, count_angle2, left_foot, count_angle3, 
left_hand, count_angle4, right_hand, count_angle5;

int main() 
{
  DDRD = 0xFC;
  DDRB = 0xFF;
  USCR0A = 0x00;
  UCSR0B = 0x10;
  UCSR0C = 0x06;
  UBRR0H = 0x00;
  UBRR0L = (16000000UL / (16UL * 9600)) - 1;
  TCNT1 = 0x00;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0X02;
  SREG = 0x80;
  home_position();
  convert();

  while (1)
  {
    while (!(UCSR0A & (1 << RXC0)));
    data = UDR0;
    if (data == '1')
    {
      foot_tap();
    }
    else if (data == '2')
    {
      leg_sweep();
    }
    else if (data == '3')
    {
      hips_out();
    }
    else if (data == '4')
    {
      hips_in();
    }
    else if (data == '5')
    {
      hands_move();
    }
    else if (data == '6')
    {
      robot_march();
    }
    else if (data == '0')
    {
      home_position();
      convert();
    }
   }
  }

void foot_tap()
{
  for (right_foot = 90; right_foot >= 80; right_foot--)
  {
    convert();
  }
  _delay_ms(20);
  for (right_foot = 80; right_foot <= 90; right_foot++)
  {
    convert();
  }
  _delay_ms(20);
}

void left_sweep()
{
  for (right_hip = 90; right_hip <= 100; right_hip++)
  {
    convert();
  }
  _delay_ms(20);
  for (right_hip = 100; right_hip >= 90; right_hip--)
  {
    convert();
  }
  _delay_ms(20);
}
void hips_out()
{
  for (int i 1; i <= 20; i++)
  {
    right_hip++;
    left_hip--;
    convert();
  }
    _delay_ms(10);
    for (int i = 1 i <= 40; i++)
    {
      right_hip--;
      left_hip++;
      convert();
    }
    _delay_ms(10);
}
void hips_in()
{
  (for i = 1; i <= 20; i++)
  {
    right_hip++;
    left_hip++;
    convert();
  }
  _delay_ms(20);
  for (int i = 1; i < 40; i++)
  {
    right_hip--;
    left_hip--;
    convert();
  }
  _delay_ms(20);
}
void hands_move();
{
  for (right_hand = 40; right_hand <= 70; right_hand++)
  {
    convert();
  }
  _delay_ms(20);
  for (right_hand = 70; right_hand >= 40; right_hand--)
  {
    convert();
  }
  _delay_ms(20);
  for (left_hand = 140; left_hand >= 110; left_hand--)
  {
    convert();
  }
    }
  }
}
