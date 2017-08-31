const int led_pin = 10;
int val = 0;
int d = 1;

void setup() {
    pinMode(led_pin, OUTPUT);
}

void loop() {
    val += d;
    analogWrite(led_pin, val);
    delay(8);
    if ((val < 1) || (val > 254)) {
        d *= -1;
    }
}
