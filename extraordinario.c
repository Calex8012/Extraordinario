#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=2000000)

int flagSerial=0, flagEcho=0, indice=0;
char caracter;

#define Max_Size_Buffer 9
char palabra[Max_Size_Buffer];


#INT_RDA
void isr_RDA(void){
   palabra[indice]=getc();
   indice++;
   flagSerial=1;
   caracter=getc();
   if(indice>palabra){
      indice=0;
   }
}

void main (void){
   while(1){
      
   }
}
