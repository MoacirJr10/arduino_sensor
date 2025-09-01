# Monitor de Temperatura com DHT11, OLED e LEDs

##  Descrição do Projeto

Este projeto implementa um sistema de monitoramento de temperatura ambiente em tempo real usando **Arduino Uno**. O sistema utiliza um sensor **DHT11** para capturar dados de temperatura, exibe as informações em um display **OLED SSD1306** e fornece indicação visual através de LEDs coloridos baseados em faixas de temperatura predefinidas.

###  Características

- Monitoramento contínuo da temperatura ambiente
- Display OLED com informações em tempo real
- Sistema de alertas visuais com LEDs coloridos
- Interface I2C para comunicação com o display
- Código otimizado e bem documentado

##  Componentes Necessários

| Componente | Quantidade | Especificação |
|------------|------------|---------------|
| Arduino Uno | 1x | Microcontrolador principal |
| Sensor DHT11 | 1x | Sensor de temperatura e umidade |
| Display OLED SSD1306 | 1x | 128x64 pixels, interface I2C |
| LED Verde | 1x | Indicador de temperatura baixa |
| LED Amarelo | 1x | Indicador de temperatura moderada |
| LED Vermelho | 1x | Indicador de temperatura alta |
| Resistores | 3x | 220Ω para limitação de corrente dos LEDs |
| Protoboard | 1x | Para montagem do circuito |
| Jumpers | - | Para conexões |

##  Diagrama de Conexões

### Display OLED SSD1306 (I2C)
```
OLED     →  Arduino Uno
GND      →  GND
VCC      →  5V
SCL(SCK) →  A5 
SDA      →  A4
```

### Sensor DHT11
```
DHT11    →  Arduino Uno
VCC      →  5V
GND      →  GND
DATA     →  Pino Digital 2
```

### LEDs com Resistores (220Ω)
```
LED Verde     →  Pino Digital 8  →  Resistor 220Ω  →  GND
LED Amarelo   →  Pino Digital 9  →  Resistor 220Ω  →  GND
LED Vermelho  →  Pino Digital 10 →  Resistor 220Ω  →  GND
```

##  Faixas de Temperatura

O sistema classifica a temperatura em três categorias:

| Faixa | Temperatura | LED | Cor |
|-------|-------------|-----|-----|
| **Baixa** | ≤ 29°C | Verde | 🟢 |
| **Moderada** | 30°C - 34°C | Amarelo | 🟡 |
| **Alta** | ≥ 35°C | Vermelho | 🔴 |

##  Bibliotecas Necessárias

Instale as seguintes bibliotecas através do **Library Manager** da Arduino IDE (`Tools` → `Manage Libraries...`):

1. **Adafruit Unified Sensor Library**
   - [ GitHub Repository](https://github.com/adafruit/Adafruit_Sensor)
   
2. **DHT Sensor Library**
   - [ GitHub Repository](https://github.com/adafruit/DHT-sensor-library)
   
3. **Adafruit SSD1306**
   - [ GitHub Repository](https://github.com/adafruit/Adafruit_SSD1306)
   
4. **Adafruit GFX Library**
   - [ GitHub Repository](https://github.com/adafruit/Adafruit-GFX-Library)

###  Como Instalar as Bibliotecas

1. Abra a Arduino IDE
2. Vá em `Tools` → `Manage Libraries...`
3. Busque pelo nome de cada biblioteca
4. Clique em `Install` para cada uma
5. Aguarde a instalação completa

##  Como Funciona

1. **Inicialização**: O sistema inicializa o sensor DHT11, o display OLED e configura os pinos dos LEDs
2. **Leitura**: O sensor DHT11 coleta dados de temperatura a cada intervalo definido
3. **Processamento**: O microcontrolador processa os dados e determina a faixa de temperatura
4. **Exibição**: A temperatura atual é exibida no display OLED em tempo real
5. **Indicação Visual**: Apenas um LED acende por vez, correspondente à faixa de temperatura atual
6. **Loop**: O processo se repete continuamente

##  Instalação e Uso

1. **Monte o circuito** seguindo o diagrama de conexões
2. **Instale as bibliotecas** necessárias na Arduino IDE
3. **Faça o upload** do código para o Arduino Uno
4. **Conecte** a alimentação e observe o funcionamento
5. **Monitore** a temperatura através do display OLED e dos indicadores LED

##  Personalização

Você pode facilmente personalizar o projeto ajustando:

- **Faixas de temperatura**: Modifique os valores limite no código
- **Intervalo de atualização**: Altere o delay entre as leituras
- **Display**: Customize as informações exibidas no OLED
- **Alertas**: Adicione buzzer ou outros tipos de notificação

##  Observações Importantes

- Certifique-se de que todas as conexões estão corretas antes de energizar o circuito
- O sensor DHT11 tem precisão de ±2°C
- Aguarde alguns segundos após ligar para estabilização das leituras
- Use resistores de 220Ω para proteger os LEDs
- Verifique se o display OLED está configurado para interface I2C

##  Contribuições

Sinta-se à vontade para contribuir com melhorias, correções de bugs ou novas funcionalidades. Abra uma issue ou envie um pull request!

**Desenvolvido  para  comunidade Arduino**
