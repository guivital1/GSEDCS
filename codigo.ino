// Configuração dos pinos
int pinbuzzer = 3;         // Piezo
int pinSensorpir = 2;      // Sensor PIR
int ledVerde = 13;         // LED verde
int ledVermelho = 12;      // LED vermelho

bool alarmeAtivado = false; // Estado do alarme

void setup() {
    // Inicialização
    Serial.begin(9600);

    pinMode(pinbuzzer, OUTPUT);       // Piezo
    pinMode(pinSensorpir, INPUT);     // Sensor PIR
    pinMode(ledVerde, OUTPUT);        // LED verde
    pinMode(ledVermelho, OUTPUT);     // LED vermelho

    digitalWrite(pinbuzzer, LOW);     // Piezo desligado
    digitalWrite(ledVerde, LOW);      // LED verde desligado
    digitalWrite(ledVermelho, LOW);   // LED vermelho desligado
}

void loop() {
    // Leitura do sensor PIR
    int valorsensorpir = digitalRead(pinSensorpir);
    Serial.print("Valor do Sensor PIR: ");
    Serial.println(valorsensorpir);

    // Controle do alarme com base no sensor
    if (valorsensorpir == HIGH) {
        ligaralarme();  // Ativar piezo e LEDs
    } else {
        desligaralarme(); // Desativar piezo e LEDs
    }
}

void ligaralarme() {
    if (!alarmeAtivado) {
        alarmeAtivado = true;          // Estado do alarme
        digitalWrite(pinbuzzer, HIGH); // Aciona o piezo
        digitalWrite(ledVerde, HIGH);  // Acende o LED verde
        digitalWrite(ledVermelho, LOW); // Apaga o LED vermelho
        tone(pinbuzzer, 292);          // Emite som
    }
}

void desligaralarme() {
    if (alarmeAtivado) {
        alarmeAtivado = false;          // Estado do alarme
        digitalWrite(pinbuzzer, LOW);   // Desliga o piezo
        digitalWrite(ledVerde, LOW);   // Apaga o LED verde
        digitalWrite(ledVermelho, HIGH); // Acende o LED vermelho
        noTone(pinbuzzer);              // Para o som
    }
}
