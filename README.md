# 🤖 ARGUS-Arm

**ARGUS-Arm** é um braço robótico de 4 graus de liberdade baseado em Arduino Mega, desenvolvido com arquitetura de controlo sincronizado multi-eixo e sistema não bloqueante baseado em `millis()`.

O projeto evoluiu de um simples controlo sequencial com `delay()` para um sistema coordenado inspirado em cinemática CNC e robótica industrial.

---

## 🚀 Funcionalidades Atuais

- 4 Graus de Liberdade:
  - Rotação da Base
  - Ombro
  - Cotovelo
  - Garra
- Movimento Pick-and-Place automatizado
- Sincronização temporal real entre os 4 eixos
- Chegada simultânea ao destino
- Sistema não bloqueante com `millis()`
- Máquina de estados estruturada
- LED indicador de atividade
- Arquitetura modular e escalável

---

## 🧠 Arquitetura de Controlo

### 🔄 Sistema Não Bloqueante
O sistema utiliza atualização periódica baseada em `millis()` (10ms), permitindo:

- Movimentos simultâneos
- Maior fluidez
- Preparação para joystick, sensores ou IA
- Eliminação total de `delay()`

---

### 🎯 Sincronização Multi-Eixo

Quando um movimento é iniciado:

- A distância de cada eixo é calculada
- A velocidade é ajustada proporcionalmente
- Todos os eixos chegam ao destino exatamente no mesmo instante

Este método é semelhante ao utilizado em:

- CNC
- Impressoras 3D
- Robótica industrial

---

### 💡 LED Indicador

- 🔵 Pisca durante movimento
- 🟢 Fixo quando todos os eixos estão estáveis

Permite diagnóstico visual rápido do estado do sistema.

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
| LED        | D13         |

---

## 🔋 Arquitetura de Alimentação

- Servos alimentados por conversor Buck regulado para 6V
- Arduino alimentado por USB
- GND comum obrigatório entre sistemas
- Bateria LiPo usada exclusivamente para os servos

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

▶ https://www.youtube.com/shorts/Esjhq-jKTh8

Repositório oficial:

▶ https://github.com/manueljoaosantos/ARGUS-Arm

---

## 📈 Versão Atual

**v1.1 – Synchronized Motion Engine**

- Sistema não bloqueante
- Sincronização dos 4 eixos
- Máquina de estados
- LED indicador de atividade

---

## 🔮 Roadmap

Próximas evoluções:

- Perfil S-curve industrial real
- Planeamento por waypoints
- Sistema híbrido Manual + Automático
- Integração com Raspberry Pi
- Sistema de visão artificial
- Integração com Inteligência Artificial (ARGUS Platform)

---

## 📜 Licença

MIT License

---

## 👤 Autor

Manuel João Santos  
Projeto integrado na plataforma ARGUS.
