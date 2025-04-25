// Define constants
#define DEBUG false  // Debug mode (true or false)
#define IS_ESP32 true  // Indicates whether the code is running on an ESP32
#define LEDC_FREQ 50000  // Frequency for LEDC (LED Control) on ESP32
#define LEDC_RESOLUTION 10  // Resolution for LEDC on ESP32 (in bits)

// DC Motor class definition
class dcMotor {
private:
    uint8_t state;  // Current state of the motor (0 - stopped, 1 - forward, 2 - reverse)
    uint8_t pin0;  // Pin for motor direction control (low side)
    uint8_t pin1;  // Pin for motor direction control (high side)
    uint8_t dutyPin;  // Pin for motor speed control (PWM)
    uint8_t channel;  // LEDC channel for PWM on ESP32
    uint16_t min;  // Minimum duty cycle value
    uint16_t max;  // Maximum duty cycle value

public:
    // Public methods
    void forward();  // Set motor to move forward
    void reverse();  // Set motor to move in reverse
    void stop();  // Stop the motor
    void setDuty(uint16_t _duty);  // Set the duty cycle for motor speed
    uint16_t getDuty();  // Get the current duty cycle
    void begin(uint8_t _pin0, uint8_t _pin1, uint8_t _dutyPin, uint8_t _channel);  // Initialize the motor
};
