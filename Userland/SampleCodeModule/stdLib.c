#include "stdLib.h"
#include <stdint.h>

extern int sysCall(int edi, int esi, int edx, int ecx);

void sysPrintString(uint8_t color, char * string){
  sysCall(1,color,string,0);
}

void sysPrintInt(uint8_t color, int num){
  sysCall(2,color,num,0);
}

void sysGetTime(int * buffer){
	buffer[0] = sysCall(3,0,0,0); // Seconds
	buffer[1] = sysCall(3,2,0,0); // Minutes
	buffer[2] = sysCall(3,4,0,0); // Hours
	buffer[3] = sysCall(3,7,0,0); // Day
	buffer[4] = sysCall(3,8,0,0); // Month
	buffer[5] = sysCall(3,9,0,0); // Year
}
