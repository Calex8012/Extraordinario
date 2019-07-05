#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=2000000)

#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O

#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_C6
   #define RX_232        PIN_C7
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1,RCV=RX_232)
   #use fast_io(c)
#endif


int flagSerial=0, flagEnter=0, llenado=0, numero=5,contador=0;
char caracter;

#INT_RDA
void isr_RDA(void){
   flagSerial=1;
   caracter=getc();
   if(contador<10){
      palabra[contador]=caracter;
      contador++;
   }
   if(caracter==0x0D){
      flagEnter=1;
   } 
}


void main (void){
   set_tris_c(0x80);
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_RDA);  
   while(1){
   
      if(flagSerial==1){
         for(int repeticion=0;repeticion<numero;repeticion++){
            putc(caracter);
         }
      }  
         flagSerial=0;
      
   }
}
