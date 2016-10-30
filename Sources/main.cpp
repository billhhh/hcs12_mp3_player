#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "music_common.h"
#include "buzz.h"

  
  
  void sing(unsigned int song) {
  
    unsigned int size = sizeof(melody) / sizeof(int);
    for (unsigned int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      unsigned int noteDuration = 1000 / tempo[thisNote];
 
      buzz(melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      unsigned int pauseBetweenNotes = noteDuration;
      MSDelay(pauseBetweenNotes); 
    }
    
  }
  

void main(void) 
{  
       
    DDRT = DDRT | 0b00100000;    // PTT5 as output
    
    sing(1); 

}