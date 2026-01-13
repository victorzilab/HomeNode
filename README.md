# 🏠 HomeNode

**HomeNode** é um projeto **open-source** de automação residencial baseado em microcontroladores, com foco em **simplicidade, modularidade e aprendizado**.

O sistema permite o controle de **relés** através de:
- 📡 **RF 433 MHz**
- 📱 **Bluetooth (HC-05)**
- 💻 Interface via **porta serial**
- 🔧 Estrutura preparada para futura integração com **ESP / MQTT**

Este projeto é desenvolvido de forma incremental e totalmente documentada, acompanhando uma **série de vídeos no YouTube**.

---

## ✨ Recursos

- Controle de **4 canais de relé** (ativo em nível lógico baixo)
- Compatível com controles RF 433 MHz
- Comunicação Bluetooth via HC-05
- Logs via porta serial
- Código simples e bem organizado
- Estrutura preparada para modularização futura
- Projeto **100% open-source**

---

## 🧰 Requisitos

### Hardware
- Arduino (Uno, Nano ou compatível)
- Receptor RF **433 MHz**
- Módulo Bluetooth **HC-05**
- Módulo de **4 relés (ativo em nível baixo)**
- Fonte de alimentação adequada
- Jumpers e protoboard (ou PCB)

### Software
- **VS Code**
- **PlatformIO** (extensão do VS Code)
- **Git**
- Drivers USB do Arduino

---

## 🚀 Como clonar e abrir o projeto

### 1️⃣ Clonar o repositório

```bash
git clone https://github.com/victorzilab/HomeNode.git
cd HomeNode
