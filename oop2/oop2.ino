struct LedPin {
    int pinNumber;
    int state = 0;

    LedPin(int _pinNumber) {
        pinNumber = _pinNumber;
    }

    void setMode(auto mode);
    
    void turn(int state);

    void toggle();
};

void LedPin::setMode(auto mode) {
    pinMode(pinNumber, mode);
}

void LedPin::turn(int updateState) {
    state = updateState;
    if (state == 0) {
        digitalWrite(pinNumber, LOW);
    }
    else {
        digitalWrite(pinNumber, HIGH);
    }
}

void LedPin::toggle() {
    state = 1 - state;
    if (state == 0) {
        digitalWrite(pinNumber, LOW);
    }
    else {
        digitalWrite(pinNumber, HIGH);
    }
}

LedPin led_pin_1(10);
LedPin led_pin_2(13);

void setup() {
    led_pin_1.setMode(OUTPUT);
    led_pin_2.setMode(OUTPUT);
}

void loop() {
    led_pin_1.turn(1);
    delay(1000);
    led_pin_1.turn(0);
    delay(1000);
    led_pin_2.toggle();
    delay(1000);
    led_pin_2.toggle();
    delay(1000);
}
