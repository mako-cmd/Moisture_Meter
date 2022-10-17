/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground through 220 ohm resistor

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInOutSerial
*/
const int sample_size = 1000;

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = 36;  // Analog input pin that the potentiometer is attached to
//const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  analogReadResolution(12);
}

void loop() {
  // read the analog in value:
  
  int buf[sample_size];
  float out = 0;
  bool flag = false;
  while(1)
  {
    //Get average of sample_size samples
    //Get sample_size samples into buffer
    for (int i = 0; i <= sample_size; i++)
    {
      if (i == sample_size)
      {
        //set flag when 1st sample_size samples have been obtained
        flag = true;
      }
      buf[i] = analogRead(analogInPin);
      //Let ADC settle
      delay(2);
    }
    //if first sample_size samples have been retrieved and saved
    if (flag == true)
    { 
      
      //Sum up and average
      for (int j = 0; j <= sample_size; j++)
      {
        out = out + buf[j];
      }
      out = out/sample_size;
      
      //Display value
      Serial.print("sensor = ");
      Serial.println(out);
    }
    else
    {
      Serial.println("Getting Initial Reading...");
    }
  // print the results to the Serial Monitor:
  }

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
}
