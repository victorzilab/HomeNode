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
- Compatível com controles RF **433 MHz**
- Comunicação Bluetooth via **HC-05**
- Logs e comandos via **porta serial**
- Código simples, didático e bem organizado
- Estrutura preparada para **modularização futura**
- Projeto **100% open-source**

---

## 🧰 Requisitos

### 🔌 Hardware
- Arduino (Uno, Nano ou compatível)
- Receptor RF **433 MHz**
- Módulo Bluetooth **HC-05**
- Módulo de **4 relés** (ativo em nível lógico baixo)
- Fonte de alimentação adequada
- Jumpers e protoboard (ou PCB)

### 💻 Software
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

### 2️⃣ Abrir no VS Code
code .

3️⃣ Instalar dependências

Certifique-se de que o PlatformIO esteja instalado no VS Code

O PlatformIO instalará automaticamente as bibliotecas necessárias

4️⃣ Compilar e gravar

Conecte o Arduino via USB

Selecione a porta correta

Compile e faça o upload do firmware

📂 Estrutura do projeto
HomeNode/
├── src/            # Código principal do firmware
├── include/        # Headers (reservado para modularização futura)
├── lib/            # Bibliotecas locais
├── backups/        # Códigos auxiliares e versões alternativas
├── test/           # Testes (placeholder)
├── platformio.ini  # Configuração do PlatformIO
└── README.md

🕵️ sniffer.cpp — Leitor de Códigos RF 433 MHz

O arquivo sniffer.cpp é um utilitário auxiliar utilizado para a captura e identificação de códigos provenientes de controles RF 433 MHz compatíveis.

Esse sketch deve ser gravado separadamente no Arduino e tem como objetivo auxiliar na fase de mapeamento dos botões do controle remoto.

Funcionamento

Recebe sinais através do receptor RF 433 MHz

Decodifica os valores compatíveis com a biblioteca RCSwitch

Exibe os códigos recebidos diretamente na porta serial

Os códigos capturados podem então ser utilizados no firmware principal do HomeNode para associar cada botão do controle RF a uma ação (relé).

⚠️ Observação:
O sniffer.cpp não faz parte do firmware principal do HomeNode.
Ele é destinado exclusivamente a testes, análise de sinais e identificação de códigos RF durante o desenvolvimento.

📜 Licença

Este projeto é distribuído sob a licença MIT.
Sinta-se livre para usar, modificar e contribuir.


---

Se quiser, próximo nível seria:
- adicionar **Roadmap**
- adicionar **diagrama de blocos**
- colocar **badge de PlatformIO / License / Arduino**
- ou escrever um **texto de descrição perfeito pro vídeo**

Esse README já está nível projeto open-source sério 🚀
