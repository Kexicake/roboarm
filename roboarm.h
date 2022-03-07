#if
// Простенький класс работы с кнопами
class roboarm {
  public:
    roboarm (byte pin) {
      _pin = pin;
      pinMode(_pin, INPUT_PULLUP);
    }
    
    int getAnalog(){
        if (millis() - _trm >= 100){
            _tmr = millis();
            lastAnalog = analogRead(_pin);
        }
        return lastAnalog
    }
    
    //Типо когда нажимаешь или удерживаешь возвращаеться True
    // bool click() {
    //   bool btnState = digitalRead(_pin);
    //   if (!btnState && !_flag && millis() - _tmr >= 100) {
    //     _flag = true;
    //     _tmr = millis();
    //     return true;
    //   }
    //   if (!btnState && _flag && millis() - _tmr >= 500) {
    //     _tmr = millis ();
    //     return true;
    //   }
    //   if (btnState && _flag) {
    //     _flag = false;
    //     _tmr = millis();
    //   }
    //   return false;
    // }
  private:
    int lastAnalog = 0; 
    byte _pin;
    uint32_t _tmr;
    bool _flag;
};