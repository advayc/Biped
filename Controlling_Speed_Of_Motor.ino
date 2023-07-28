#include <avr/io.h>
#include <avr/interrupt.h>
#define setbit(x,y) (x |= y)
#define clearbit(x,y)(x &=~y)
#define bitn(p) (0x01 << (p))
#include <LCD.h>
#define checkbit(x,y) ((x) & (y))
int count, angle,angle1,count_angle,count_angle1;
int main(void)
{
  DDRD = 0xFF;
TCNT1 =0x00;
OCR1A = 21;
TCCR1A = 0x00;
TCCR1B = 0x0A;
TIMSK1 =0x02;
SREG=0x80;
homeposition();
_delay_ms(2000);
while(1)
  {
    for (angle = 90; angle <= 130; angle++)
    {
      convert();
    }
    for (angle = 130; angle >= 90; angle--)
    {
      convert_slow();
    }
  }
}
void convert()
{
  count_angle = + 46;
  _delay_us(3000);
}
void convert_slow()
{
  count_angle = angle + 46;
  _delay_us(3500);
}
void homeposition()
{
  angle = 90;
}
ISR (TIMER1_COMPA_vect)
{
  count++;
  if (count <= count-angle)
  {
    setbit(PORTD, bitn(4));
  }
  else if ((count > count_angle) && (count < 1818))
  {
    clearbit(PORTD, bitn(4));
  }
  else if (count >= 1818)
  {
    count = 0;
  }
}
