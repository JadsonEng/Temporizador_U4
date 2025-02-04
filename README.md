#Jadson de Jesus Santos - Tarefa de Clock e Temporizadores: Semáforo

📚 ##Apresentação

Este projeto implementa um sistema de semáforo utilizando o Raspberry Pi Pico W SDK no VSCode e o simulador Wokwi Online, que foi integrado ao VSCode. 
O código foi desenvolvido utilizando a API de hardware de temporização repetitiva para alternar automaticamente entre os LEDs representando os sinais de trânsito.

🎯 ##Objetivo

Compreender o funcionamento do temporizador fornecido pela API de Hardware add_repeating_timer_ms

📑 ##Requisitos

- Visual Studio Code;
- Extensões C/C++, CMAKE e Raspberry Pi Pico no VSCode;
- Simulador Wokwi Online.

📋 ##Funcionamento

- A API de Hardware chama a função callback que executa o acionamento dos LEDs;
- O acionamento dos LEDs ocorre por meio de uma função de repetição, de forma assíncrona;
- Paralelamente ao semáforo, uma mensagem no terminal será exibida a cada 1000ms (1 segundo) de acordo com o LED ligado;
- Vermelho: "Stop!"
- Amarelo: "Attention!"
- Verde: "Go!"
