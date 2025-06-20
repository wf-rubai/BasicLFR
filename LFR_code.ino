const int lfo = 3;  // motor driver left front output
const int lbo = 2;  // motor driver left back output
const int rfo = 5;  // motor driver right front output
const int rbo = 6;  // motor driver right back output

const int lfi = 8;   // motor driver left front input
const int lbi = 9;   // motor driver left back input
const int rfi = 11;  // motor driver right front input
const int rbi = 12;  // motor driver right back input

const int seid = 4;   // speed encoder input digital
const int seia = A3;  // speed encoder input analog

const int iriaf = A0; // IR sensor input analog front
const int irial = A1; // IR sensor input analog left
const int iriar = A2; // IR sensor input analog right

const int ireo = 10;  // IR emitter PWM output 38kHz (OC1B)

void setup() {
  Serial.begin(9600);

  pinMode(iriaf, INPUT);
  pinMode(irial, INPUT);
  pinMode(iriar, INPUT);
  pinMode(seid, INPUT);
  pinMode(ireo, OUTPUT);  // IR emitter output

  setup38kHzPWM();  // Enable 38kHz PWM on Pin 10
}

void loop() {
  int a1 = analogRead(irial);
  int a2 = analogRead(iriar);
  int a0 = analogRead(iriaf);
  int d4 = digitalRead(seid);

  Serial.print(a1);
  Serial.print("\t\t");
  Serial.print(a2);
  Serial.print("\t\t");
  Serial.print(a0);
  Serial.print("\t\t");
  Serial.println(d4);

  delay(100);
}

// === Setup 38kHz PWM on Pin 10 ===
void setup38kHzPWM() {
  // Use Timer1 (16-bit) for 38kHz on OC1B (Pin 10)
  TCCR1A = _BV(COM1B1) | _BV(WGM11);                  // Non-inverting PWM on OC1B, mode 14
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);       // Fast PWM, no prescaler
  ICR1 = 421;                                         // TOP value: 16MHz / 38kHz = ~421
  OCR1B = 210;                                        // 50% duty cycle
}
