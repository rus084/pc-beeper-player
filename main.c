#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#include "muspcm.h"
//#include "example8b.h"

// #define BASEPORT 0x378 //printer port
#define BASEPORT 0x61 // speaker port
#define CYCLE_WAIT 168
void wait(int cycles) {
	int count=0;
	while (count < (CYCLE_WAIT*cycles)) {
		__asm__ __volatile__ ("nop");
		count++;
	}
}

int main()
{
	printf("	pc beeper wav player v0.1/r/n");
	printf("	©2015 Sidin Dmitriy/r/n");
	int i=0;
	//int counter ;
	int data=0;
	if (ioperm(BASEPORT, 1, 1)) {perror("ioperm"); exit(1);}
	while (1) {

  	data = mus_raw[i++];
  	//data = example8_raw[i++];
	//data++;
  	outb( 0x00  , BASEPORT); //v2
  	wait(data);
  	outb( 0x02  , BASEPORT);
  	wait(0xff-data);

	}

	if (ioperm(BASEPORT, 1, 0)) {perror("ioperm"); exit(1);}
	exit(0);
}


