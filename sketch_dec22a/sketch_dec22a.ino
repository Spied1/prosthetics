#include <Servo.h>

Servo servo;
int servoPin = 7;

class Prosthetic
{
private:
  int signalValue;
  int thresholder;
  int analogPin0;
  bool signalCheck;
  int reductedSignal;

public:
  Prosthetic():
  thresholder(370)
  ,signalCheck(false)
  ,signalValue(0)
  ,analogPin0(A0)
  ,reductedSignal(0)
  {
  }

  int get_signal()
  {
    signalValue = analogRead(analogPin0);
    return signalValue;
  }

  int noise_reduction()
  {
    reductedSignal = get_signal();
    return reductedSignal;
  }
//reductedSignal = noise_reduction();
  bool check()
  {
    
    reductedSignal = get_signal();
    if (reductedSignal > thresholder)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
}

bool state = 0;
int state_c = 0;

void loop() {
  static Prosthetic hand;

  if(hand.check() == 1)
  {
    if(state_c != 180)
    {
      state_c += 180;
    }
    else if(state_c == 180)
    {
      state_c = 0;
    }
    servo.write(state_c); 
    delay(1000);
  }
  Serial.println(state_c);
}