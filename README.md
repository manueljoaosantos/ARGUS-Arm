# 🤖 ARGUS-Arm

**ARGUS-Arm** é um braço robótico de 4 graus de liberdade baseado em Arduino Mega, desenvolvido para executar movimentos sequenciais do tipo pick-and-place com controlo estável e alimentação externa dedicada para os servos.

Este projeto foca-se em:
- Alinhamento mecânico correto
- Estabilidade elétrica
- Movimento previsível e controlado
- Estrutura modular e expansível

---

## 🚀 Funcionalidades

- 4 Graus de Liberdade:
  - Rotação da Base (±45°)
  - Ombro
  - Cotovelo
  - Garra
- Movimento sequencial automático
- Limites de servo configuráveis
- Alimentação externa estabilizada (6V)
- Código estruturado e organizado
- Arquitetura preparada para expansão futura

---

## 🛠 Componentes Utilizados

- Arduino Mega 2560
- 4x Servos MG996R
- Bateria LiPo 3S (11.1V 2000mAh 40C)
- Conversor DC Buck 10A (regulado para 6V)
- Alimentação externa dedicada aos servos
- GND comum entre alimentação dos servos e Arduino

---

## 🔌 Configuração de Pinos

| Função     | Pino Arduino |
|------------|-------------|
| Base       | D2          |
| Ombro      | D3          |
| Garra      | D4          |
| Cotovelo   | D5          |

---

## ⚙ Sequência de Movimento Atual

O sistema executa automaticamente a seguinte sequência:

1. Ombro sobe  
2. Cotovelo estende  
3. Base roda para a direita (+45°)  
4. Garra fecha (apanha objeto)  
5. Base roda para a esquerda (-90° total)  
6. Garra abre (larga objeto)  
7. Base regressa ao centro  
8. Cotovelo recolhe  
9. Ombro desce  

---

## 🔋 Arquitetura de Alimentação

- Servos alimentados por conversor Buck ajustado para 6V
- Arduino alimentado por USB
- GND comum entre os dois sistemas
- Bateria LiPo 11.1V utilizada apenas para os servos

⚠️ Nunca alimentar os servos diretamente pelo 5V do Arduino.

---

## 📂 Estrutura do Projeto

ARGUS-Arm/
│
├── ARGUS_Arm_v1.ino
├── README.md
├── LICENSE
└── docs/


---

## 🧠 Objetivos do Projeto

- Criar uma plataforma robótica modular
- Garantir estabilidade elétrica com múltiplos servos
- Desenvolver movimento controlado e previsível
- Permitir futura integração com:
  - Joystick
  - Sensores
  - Visão computacional
  - Inteligência Artificial

---

## 🔮 Melhorias Futuras

- Modo de controlo manual por joystick
- Ativação por botão
- Sistema não bloqueante (uso de millis())
- Gravação de posições
- Integração com Raspberry Pi
- Sistema de visão artificial

---

## 📹 Demonstração

O ARGUS-Arm em funcionamento (Pick & Place automático):

[▶ Ver no YouTube](https://www.youtube.com/shorts/Esjhq-jKTh8)

---

## 📜 Licença

Distribuído sob a licença MIT.

---

## 👤 Autor

Manuel João Santos  
Projeto integrado na plataforma ARGUS.

---
