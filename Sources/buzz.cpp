#include "buzz.h"
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

void buzz(unsigned int frequency, unsigned int length) {

  unsigned int delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  unsigned int numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  
  for (unsigned int i = 0; i < numCycles; i++) { // for the calculated length of time...
    PTT = PTT | 0x20;      //make PT5=1 write the buzzer pin high to push out the diaphram
    MSDelay(delayValue); // wait for the calculated delay value
    PTT = PTT & 0xDF;      //Make PT5=0 write the buzzer pin low to pull back the diaphram
    MSDelay(delayValue); // wait again or the calculated delay value
  }
  
}

//millisecond delay for XTAL=8MHz, PLL=48MHz
//The HCS12 Serial Monitor is used to download and  the program.
//Serial Monitor uses PLL=48MHz
 void MSDelay(unsigned int itime)
  {
    unsigned int i;
    unsigned int j;
    
    for(i=0;i<itime;i++)
      for(j=0;j<4000;j++);    //1 msec. tested using Scope
  }