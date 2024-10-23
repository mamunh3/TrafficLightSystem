// Class - TrafficLights
class TrafficLights {
	public:
  		int pinG = 10;
		int pinY = 9;
		int pinR = 8;
		int interval_1 = 1000; // 10s
		int interval_2 = 200; // s
  		int pedestrianR = 11;
  		int pedestrianG = 12;
  		char currentState = 'G';
  
    void init() {
      pinMode(this->pinG, OUTPUT);
      pinMode(this->pinY, OUTPUT);
      pinMode(this->pinR, OUTPUT);
      pinMode(this->pedestrianR, OUTPUT);
      pinMode(this->pedestrianG, OUTPUT);
    }

    void greenSignal() {
      digitalWrite(pinG, HIGH);
      delay(interval_1);
      digitalWrite(pinG, LOW);
      digitalWrite(pedestrianR, HIGH);
      digitalWrite(pedestrianG, LOW);      
      currentState = 'Y';
    }

    void yellowSignal() {
      digitalWrite(pinY, HIGH);
      delay(interval_2);
      digitalWrite(pinY, LOW);
      currentState = 'R';
    }

    void redSignal() {
      digitalWrite(pinR, HIGH);
      delay(interval_1);
      digitalWrite(pinR, LOW);
      digitalWrite(pedestrianG, HIGH);
      digitalWrite(pedestrianR, LOW);
      
      currentState = 'G';
    }
};

// Object
TrafficLights light;

void setup()
{
  light.init();
}

void loop()
{

  switch(light.currentState){
   case 'G':
    // Green Light
  	light.greenSignal();
    break;
   case 'Y':
    // Yellow Light
  	light.yellowSignal();
    break;
   case 'R':
    // Red Light
  	light.redSignal();
    break;	
  }
}