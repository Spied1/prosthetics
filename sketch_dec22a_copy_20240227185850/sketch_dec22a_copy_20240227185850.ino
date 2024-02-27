class Prosthetic
{
private:
	int signalValue;
	int thresholder;
	int analogPin0;
	bool signalCheck;
  int reductedSignal;
public:
	Prosthetic():thresholder(360),signalCheck(false),signalValue(0),analogPin0(A0),reductedSignal(0)
	{
	}

	int get_signal()
	{
		signalValue = analogRead(analogPin0);
		return signalValue;
	}

	int noise_reduction()
	{
		int reductedSignal = get_signal();
		return reductedSignal;
	}

	bool check()
	{
		reductedSignal = noise_reduction();
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
  Serial.begin(9600);
}

void loop() {
  static Prosthetic hand;
  Serial.println(hand.noise_reduction());
  Serial.println(hand.check());
  delay(100); // Задержка для улучшения читаемости вывода
}

