#ifndef MATRIZ_LED_H
#define MATRIZ_LED_H

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "generated/ws2812.pio.h"


#define PINO_WS2812 7
#define RGBW_ATIVO false
#define NUM_PIXELS 25

void inicializar_matriz_led();
void enviar_pixel(uint32_t pixel_grb);
void mostrar_numero(uint8_t num);

#endif