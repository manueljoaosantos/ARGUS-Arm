# 🤖 ARGUS-Arm

**ARGUS-Arm** é um braço robótico de 4 graus de liberdade baseado em Arduino Mega, projetado para executar movimentos sequenciais do tipo **pick-and-place com controlo cinemático estável e gestão real de estado dos servos**.

Este projeto evoluiu de um simples controlo de servos para uma arquitetura estruturada com:

- Controlo determinístico
- Compactação mecânica antes de rotação
- Sequência simétrica de trabalho
- Gestão de posição real (sem saltos entre ciclos)
- Base preparada para aceleração progressiva

---

## 🚀 Funcionalidades

- 4 Graus de Liberdade:
  - Rotação da Base (amplitude configurável)
  - Ombro
  - Cotovelo
  - Garra
- Movimento automático tipo pick-and-place
- Compactação automática antes de rotação
- Gestão de posição real dos servos
- Eliminação de saltos no reinício do ciclo
- Alimentação externa dedicada aos servos (6V estabilizado)
- Arquitetura modular preparada para aceleração suave

---

## 🧠 Arquitetura de Controlo

O sistema mantém o **estado real de cada servo**, evitando:

- Saltos no reinício do loop
- Movimentos bruscos ao inverter direção
- Torque excessivo durante rotação
- Descida do ombro sob carga indevida

### Sequência de movimento otimizada:

Centro (trabalho)
→ Esquerda (trabalho)
→ Centro
→ Direita (trabalho)
→ Centro


Sempre com:
- Ombro elevado antes de rodar
- Cotovelo recolhido antes de rodar
- Descida controlada apenas após estabilização

---

## 🛠 Componentes Utilizados

- Arduino Mega 2560  
- 4x Servos MG996R  
- Bateria LiPo 3S (11.1V 2000mAh 40C)  
- Conversor DC Buck 10A ajustado para 6V  
- Alimentação externa dedicada aos servos  
- GND comum entre servos e Arduino  

---

## 🔌 Configuração de Pinos

| Função     | Pino Arduino |
|------------|-------------|
| Base       | D2          |
| Ombro      | D3          |
| Cotovelo   | D4          |
| Garra      | D5          |

---

## 🔋 Arquitetura de Alimentação

- Servos alimentados por conversor Buck regulado para 6V
- Arduino alimentado por USB
- GND comum entre alimentação dos servos e Arduino
- Bateria LiPo utilizada exclusivamente para os servos

⚠️ Nunca alimentar servos diretamente pelo 5V do Arduino.

---

## 📂 Estrutura do Projeto

ARGUS-Arm/
│
├── ARGUS_Arm_v1.ino
├── README.md
├── LICENSE
└── docs/


---

## 📹 Demonstração

ARGUS-Arm em funcionamento (Pick & Place automático):

▶ https://www.youtube.com/shorts/Esjhq-jKTh8

Repositório oficial:

▶ https://github.com/manueljoaosantos/ARGUS-Arm

---

## 🔮 Roadmap

Próxima evolução planeada:

- Aceleração progressiva suave (perfil industrial)
- Sistema não bloqueante (millis)
- Modo manual por joystick
- Gravação e reprodução de movimentos
- Integração com Raspberry Pi
- Visão computacional
- Integração com IA (ARGUS Platform)

---

## 📜 Licença

MIT License

---

## 👤 Autor

Manuel João Santos  
Projeto integrado na plataforma ARGUS.
