//ALL HAIL Shinigami, a good kitty
//GPL v3.0
// @Author S.D. Barnett
//all use must adhere to license copy provided here:  https://www.gnu.org/licenses/gpl-3.0.en.html

/*
 @Description :  simple universal class to control a DCMOTOR
 
  */

// Initialize the motor
void dcMotor::begin(uint8_t _pin0, uint8_t _pin1, uint8_t _dutyPin, uint8_t _channel) {
    pin0 = _pin0;  // Set the low side control pin
    pin1 = _pin1;  // Set the high side control pin
    dutyPin = _dutyPin;  // Set the PWM control pin
    channel = _channel;  // Set the LEDC channel (for ESP32)

    min = 0;  // Set the minimum duty cycle value
    max = 254;  // Set the maximum duty cycle value (default for non-ESP32)

    // Set the pins as output
    pinMode(pin0, OUTPUT);
    pinMode(pin1, OUTPUT);
    pinMode(dutyPin, OUTPUT);

    // If running on ESP32, configure LEDC
    #ifdef IS_ESP32
        max = 1023;  // Set the maximum duty cycle value for ESP32
        ledcAttachChannel(dutyPin, LEDC_FREQ, LEDC_RESOLUTION, channel);
    #endif
}

// Stop the motor
void dcMotor::stop() {
    digitalWrite(pin0, 0);  // Set both control pins low to stop the motor
    digitalWrite(pin1, 0);
    state = 0;  // Set the motor state to stopped
}

// Set motor to move forward
void dcMotor::forward() {
    digitalWrite(pin0, 0);  // Set the low side control pin low
    digitalWrite(pin1, 1);  // Set the high side control pin high
    state = 1;  // Set the motor state to forward
}

// Set motor to move in reverse
void dcMotor::reverse() {
    digitalWrite(pin0, 1);  // Set the low side control pin high
    digitalWrite(pin1, 0);  // Set the high side control pin low
    state = 2;  // Set the motor state to reverse
}

// Set the duty cycle for motor speed
void dcMotor::setDuty(uint16_t _duty) {
    #ifdef IS_ESP32
        ledcAttachChannel(dutyPin, LEDC_FREQ, LEDC_RESOLUTION, channel);  // Set the PWM duty cycle using LEDC
    #else
        analogWrite(dutyPin, _duty);  // Set the PWM duty cycle using analogWrite
    #endif
}

// Get the current duty cycle
uint16_t dcMotor::getDuty() {
    #ifdef IS_ESP32
        return ledcRead(dutyPin);  // Read the PWM duty cycle using LEDC
    #else
        return analogRead(dutyPin);  // Read the PWM duty cycle using analogRead
    #endif
}

bool dcMotor::calibrate(){
return true
}
