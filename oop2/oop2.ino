struct LedPin {
    int pinNumber;
    int state;
    String type;

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

LedPin lp(10);

void setup() {
}

void loop() {
    lp.turn(1);
    delay(1000);
    lp.turn(0);
    delay(1000);
    lp.toggle();
    delay(1000);
    lp.toggle();
    delay(1000);
}
