struct LedPin {
    int pinNumber;
    int state;
    String type;

    LedPin(int _pinNumber, String _type) {
        pinNumber = _pinNumber;
        type = _type;
    }
    ~LedPin();

    void setMode() {
        if (type == "in") {
            pinMode(pinNumber, INPUT);
        } 
        else if (type == "out") {
            pinMode(pinNumber, OUTPUT);
        }
        else if (type == "inpu") {
            pinMode(pinNumber, INPUT_PULLUP);
        }
    }
    
    void turnOn() {
        digitalWrite(pinNumber, HIGH);
    }

    void turnOff() {
        digitalWrite(pinNumber, LOW);
    }
};

void setup() {
}

void loop() {
    static LedPin lp(10, "out");
    lp.turnOn();
    delay(1000);
    lp.turnOff();
    delay(1000);
}
