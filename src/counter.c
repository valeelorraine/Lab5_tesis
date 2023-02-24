//*****************************************************************************************
//                                 L I B R E R Í A S  
//*****************************************************************************************

#include "counter.h"
#include <Arduino.h>
#include "button.h"

// ====================================================================================================
// Private variables
// ====================================================================================================
static int leds[4];

// ====================================================================================================
// Private functions
// ====================================================================================================


// ====================================================================================================
// Public function definitions
// ====================================================================================================
void
mostrar_contador(contadorled_t * p_self)
{
   for (int i = 0; i < 4; i++){
    leds[i] = bitRead(p_self->numero,i);  // parámetro interno del h
   }
   digitalWrite(p_self->led1, leds[0]);
   digitalWrite(p_self->led2, leds[1]);
   digitalWrite(p_self->led3, leds[2]);
   digitalWrite(p_self->led4, leds[3]);
}

void 
contador_incrementar(contadorled_t*p_self, button_t *boton1, button_t *boton2)
{
   if(presionado(boton1) == 1){
      p_self->FLAG1 = 1;
    }
   else{
      if (p_self->FLAG1 == 1){
         p_self->FLAG1 = 0;
         p_self->numero++;                        // encender led2
    }
  }  


   if(presionado(boton2) == 1){
      p_self->FLAG2 = 1;
   }
   else{
      if (p_self->FLAG2 == 1){
         p_self->FLAG2 = 0;
         p_self->numero--;                        // encender led2
    }
  }  

}