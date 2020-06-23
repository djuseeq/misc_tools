#include <Arduino.h>
#include <adcFilter.h>

    void setup() {
    	Serial.begin(9600);
    }//end setup
    
    void loop() {
    	uint16_t rawAdc = filteredAnalog(A0); //read filtered ADC value from A0 pin
    	Serial.println("ADC :" + (String)rawAdc);
    	delay(2000);
    }
