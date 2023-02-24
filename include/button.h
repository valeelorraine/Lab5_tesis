/** @file button.h
 *
 * @brief Prototipos de funciones del tipo boton.
 *
 * @par
 */

#ifndef BUTTON_H
#define BUTTON_H

#ifdef __cplusplus
extern "C"
{
#endif

// ====================================================================================================
// Dependencies
// ====================================================================================================
#include <stdint.h>
#include <Arduino.h>

// ====================================================================================================
// Macro definitions (public)
// ====================================================================================================

// ====================================================================================================
// Type definitions
// ====================================================================================================
    typedef struct
    {
        /* data */
        uint8_t pin;       
        bool switcheo;  
    } button_t;

// ====================================================================================================
// Public function definitions
// ====================================================================================================
    /**
     * @brief Inicializa el objeto (estructura) del tipo boton.
     *
     * @param[in, out] p_self   Puntero a la estructura boton.
     */

    static inline void
    boton_init(button_t *p_self, uint8_t pin)
    {
        p_self->pin = pin;
        p_self->switcheo = false;
    }

// ====================================================================================================
// Public function prototypes
// ====================================================================================================

    uint8_t
    presionado(button_t *p_self);          // Determinar si está presionado el boton

    bool 
    estado_boton3(button_t *p_self);       // Estado del boton 3


#ifdef __cplusplus
}
#endif

#endif /* BUTTON_H */

/*** end of file ***/
