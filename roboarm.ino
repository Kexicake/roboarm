#include <Servo.h>

// Библеотека для работы с сигналами от датчика ЭКГ
#include "roboarm.h"
#include "button.h"

#define pinServo A5
#define pinEKG 0

// int max_analog_dta      = 500;              // max analog data
// int min_analog_dta      = 350;              // min analog data
// int static_analog_dta   = 0;                // static analog data
// int k = 0;
// int diff = 0;
// int dif2 = 0;
// int pV = 0;
// int cV = 0;
// int b = 0;
// int n = 30;
// int y = 0;
// int arr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
// int arr2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
// bool statys;
Servo servo;
// Servo servo1;
roboarm roboarm1(pinEKG);

button but(pinEKG);
// get analog value
// int getAnalog(int pin)
// {
//     long sum = 0;
    
//     for(int i=0; i<32; i++)
//     {
//         sum += analogRead(pin);
//     }
    
//     int dta = sum>>5;
    
//     max_analog_dta = dta>max_analog_dta ? dta : max_analog_dta;         // if max data
//     min_analog_dta = min_analog_dta>dta ? dta : min_analog_dta;         // if min data
    
//     return sum>>5;
// }

void setup()
{
    servo.attach(pinServo);
    // servo1.attach(7);

    Serial.begin(115200);
    
    // long sum = 0;

    // for(int i=0; i<=10; i++)
    // {
    //     for(int j=0; j<100; j++)
    //     {
    //         sum += getAnalog(A0);
    //         delay(1);
    //     }        
    // }
    
    // sum /= 1100;
    
    // static_analog_dta = sum;

    // Serial.print("static_analog_dta = ");
    // Serial.println(static_analog_dta);
    servo.write(0);
    delay(1000);
    servo.write(100);
    delay(1000);
    servo.write(0);
}
uint32_t tmr = millis();
bool fl = false;
void loop() {
  
    Serial.println(roboarm1.getAnalog());
    // int val = getAnalog(A0);                    // get Analog value
    // cV = analogRead(0);  

  // Часть кода которая обрабатывает поворот серво через кнобку без задержек в коде
  if (but.click()){
    servo.write(180);
    tmr = millis();
    fl = true;
  }else if(millis()-tmr >= 250 && fl){
    servo.write(0);
    fl = false;
  }
}
