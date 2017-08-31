const int button_pin = 8;
const int led_pin = 13;
bool buttonPressed = false;

void readButton() {
    if (digitalRead(button_pin) == LOW) {
        buttonPressed = true;
    }
    else {
        buttonPressed = false;
    }
}

void setup() {
    pinMode(button_pin, INPUT_PULLUP);
    pinMode(led_pin, OUTPUT);
}

void loop() {
    readButton();
    if (buttonPressed) {
        digitalWrite(led_pin, HIGH);
    }
    else {
        digitalWrite(led_pin, LOW);
    }
}
