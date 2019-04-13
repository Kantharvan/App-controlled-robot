#include<stdio.h>
#include<reg52.h>
unsigned int a;
//unsigned int i,j;
void receive()
{
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
	while(RI==0);
	a=SBUF;
	RI=0;
}
void delay( unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<1275;j++);
		}
}

void f()
{
	P2=0x0a;
	delay(200);
}
void back()
{
	P2=0x05;
	delay(200);
}
void l()
{
	P2=0x09;
	delay(145);
}
void r()
{
	P2=0x06;
	delay(145);
}
void s()
{
	P2=0x00;
}

void one()
{
	f();
	f();
	s();
	return;
}

void two()
{	int i;
	for(i=0;i<3;i++)
	{
	r();
	f();
	}
	for(i=0;i<2;i++)
	{
		l();
		f();
	}
	l();
	s();
	return;
}

void three()
{
	int i;
	for(i=0;i<3;i++)
	{
	r();
	f();
	}
	back();
	l();
	f();
	r();
	f();
	r();
	s();
	return;
}
void four()
{
	int i;
	back();
	r();
	f();
	l();
	f();
	back();
	back();
	s();
	return;
}
void five()
{
	int i;
	for (i = 0; i < 3; ++i)
	{
		l();
		f();
	}
	for (i = 0; i < 2; ++i)
	{
		r();
		f();
	}
	s();
	return;
}
void six()
{
	int i;
	for (i = 0; i < 2; ++i)
	{
		r();
		f();
	}
	f();
	for (i = 0; i < 3; ++i)
	{
		l();
		f();
	}
	r();
	s();
	return;
}
void seven()
{
	int i;
	for (i = 0; i < 2; ++i)
	{
		r();
		f();
	}
	f();
	l();
	delay(290);
	s();
	return;
}
void eight()
{
	int i;
	for (i = 0; i < 3; ++i)
	{
		r();
		f();
	}
	for (i = 0; i < 4; ++i)
	{
		l();
		f();
	}
	r();
	f();
	s();
	return;
}
void nine()
{
	int i;
	for (i = 0; i < 4; ++i)
	{
		l();
		f();
	}
	back();
	back();
	s();
	return;
}
void square()
{
	int k;
	for(k=0;k<4;k++)
	{
		f();
		f();
		r();
	}
	s();
	return;
}
void main()
	{
		while(1)
		{
			receive();
			if(a=='f')
				P2=0x0a;
			if(a=='b')
				P2=0x05;
			if(a=='l')
				P2=0x09;
			if(a=='r')
				P2=0x06;
			if(a=='s')
				P2=0x00;
			if (a=='z')
				square();
			if(a=='o')
				one();
			if(a=='t')
				two();
			if(a=='h')
				three();
			if(a=='u')
				four();
			if(a=='i')
				five();
			if(a=='x')
				six();
			if(a=='v')
				seven();
			if(a=='e')
				eight();
			if (a=='n')
				nine();
		}
	}
	








