#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/irq.h"
#include "matriz_led.h"
#include "numeros.h"
#include "generated/ws2812.pio.h"

#define RGBW_ATIVO false
#define PINO_WS2812 7
#define PINO_LED_R 13
#define PINO_LED_G 12
#define PINO_LED_B 11
#define PINO_BOTAO_A 5
#define PINO_BOTAO_B 6
#define ATRASO_DEBOUNCE 400

volatile uint8_t numero_atual = 0;
volatile uint64_t tempo_ultima_interrupcao = 0;

void callback_gpio(uint gpio, uint32_t eventos) {
    uint64_t tempo_atual = time_us_64();
    if (tempo_atual - tempo_ultima_interrupcao < ATRASO_DEBOUNCE * 1000) return;

    if (gpio == PINO_BOTAO_A) {
        numero_atual = (numero_atual + 1) % 10;
    } else if (gpio == PINO_BOTAO_B) {
        numero_atual = numero_atual > 0 ? numero_atual - 1 : 9;
    }

    mostrar_numero(numero_atual);
    tempo_ultima_interrupcao = tempo_atual;
}

int main() {
    stdio_init_all();

    // Configuração dos pinos
    gpio_init(PINO_LED_R);
    gpio_set_dir(PINO_LED_R, GPIO_OUT);

    gpio_init(PINO_BOTAO_A);
    gpio_init(PINO_BOTAO_B);
    gpio_set_dir(PINO_BOTAO_A, GPIO_IN);
    gpio_set_dir(PINO_BOTAO_B, GPIO_IN);
    gpio_pull_up(PINO_BOTAO_A);
    gpio_pull_up(PINO_BOTAO_B);

    // Configuração das interrupções
    gpio_set_irq_enabled_with_callback(PINO_BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &callback_gpio);
    gpio_set_irq_enabled(PINO_BOTAO_B, GPIO_IRQ_EDGE_FALL, true);

    // Inicialização da matriz de LEDs
    inicializar_matriz_led();

    // Mostrar o número inicial
    mostrar_numero(numero_atual);

    // Loop principal
    while (1) {
        gpio_put(PINO_LED_R, 1);
        sleep_ms(100);
        gpio_put(PINO_LED_R, 0);
        sleep_ms(100);
    }

    return 0;
}