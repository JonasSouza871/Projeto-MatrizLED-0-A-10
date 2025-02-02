# 🎮 Projeto Matriz LED

Exibição de números (0-9) em uma matriz LED 5x5 usando Raspberry Pi Pico W.

## 🔧 Hardware

- Raspberry Pi Pico W
- Matriz LED WS2812 5x5 (25 LEDs)
- 2 Botões
- Jumpers

### 📍 Pinagem

```
LED Matrix (WS2812) -> GP7
LED Vermelho -> GP13
LED Verde -> GP12
LED Azul -> GP11
Botão A (Incremento) -> GP5
Botão B (Decremento) -> GP6
```

## 💻 Software Necessário

- SDK Raspberry Pi Pico (v2.1.0)
- CMake (v3.13+)
- VS Code + Extensão Pico
- GCC ARM (v13_3_Rel1)
- Git

## 📁 Estrutura do Projeto

```
.
├── .vscode/          # Configurações VS Code
├── generated/        # Headers PIO gerados
├── CMakeLists.txt   # Config. build
├── main.c           # Código principal
├── matriz_led.c     # Funções da matriz
├── matriz_led.h     # Header da matriz
├── numeros.c        # Padrões dos números
├── numeros.h        # Header dos números
└── ws2812.pio      # Programa WS2812
```

## ⚡ Como Usar

### Clonar
```bash
git clone https://github.com/seu-usuario/projeto-matriz-led.git
cd projeto-matriz-led
```

### Compilar
```bash
mkdir build
cd build
cmake ..
make
```

### Programar o Pico
1. Segure BOOTSEL e conecte o Pico
2. Solte o botão
3. Copie `ws2812.uf2` para o Pico
4. Pronto!

## 🚀 Funcionamento

- ▶️ Exibe números de 0-9
- ➕ Botão A aumenta o número
- ➖ Botão B diminui o número
- 🔄 Sistema circular (9 -> 0 ou 0 -> 9)
- ⏱️ Debounce de 400ms nos botões
- 💡 LED vermelho pisca a cada 200ms

### 📊 Componentes do Código

1. **main.c**
   - Inicialização dos pinos
   - Controle dos botões
   - Loop principal

2. **matriz_led.c/h**
   - Controle da matriz WS2812
   - Envio de dados para LEDs

3. **numeros.c/h**
   - Padrões dos números
   - Matriz 5x5 para cada número

4. **ws2812.pio**
   - Protocolo WS2812
   - Timing dos LEDs

## 🐛 Debug

- Saída serial via USB
- LED vermelho indica funcionamento
- Use `printf` para debug

## Esquemático


 ## 🔗 Link do Vídeo de Funcionamento:

 ## 📞 Contato:

 - 👤 **Autor**:

 - - 📧 **E-mail**:
