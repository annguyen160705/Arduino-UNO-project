#define BLYNK_TEMPLATE_ID "TMPL60fofB7Bz"
#define BLYNK_TEMPLATE_NAME "BÁO CHÁY"
#define BLYNK_AUTH_TOKEN "FCOGzticfy1kwQs2hIbkEq5XCTiXRMHq"
#include <DHT.h> //Khai báo thư viện DHT để làm việc với cảm biến nhiệt độ
và độ ẩm DHT
#include <BlynkSimpleEsp8266.h> //Khai báo thư viện Blynk để kết nối với
nền tảng IoT Blynk sử dụng ESP8266.
#define DHTTYPE DHT11
const int DHTPin = D1;
const int analogMQ5 = A0;
float analogValue;
DHT dht(DHTPin, DHTTYPE);
static char temp[7];
char auth[] = "FCOGzticfy1kwQs2hIbkEq5XCTiXRMHq"; // Thay thế bằng Auth
Token bạn nhận được
char ssid[] = "THEBEONE"; // Thay thế bằng tên mạng Wi-Fi của bạn
char pass[] = "05072001"; // Thay thế bằng mật khẩu Wi-Fi của bạn
void setup() {
Serial.begin(9600);
delay(10);
dht.begin();
Blynk.begin(auth, ssid, pass);
}
void loop() {
analogValue = analogRead(analogMQ5); //Đọc giá trị analog từ cảm biến
gas MQ5 và in ra nếu phát hiện gas vượt quá một ngưỡng
if (analogValue >= 400) { //Nếu nồng độ khí gas quá 400ppm
thì in ra màn hình "Phát hiện khí gas" và ngược lại
Serial.println("Phát hiện gas!");
}
else Serial.println("Không phát hiện gas");
Serial.println(analogValue);
//cảm biến nhiệt DHT11
float t = dht.readTemperature(); //Khai báo biến
delay(2000);
Serial.print("nhiệt độ: "); //đọc nhiệt độ từ cảm biến DHT, in ra màn
hình
Serial.println(t);
Blynk.virtualWrite(V6, t);Gửi giá trị nhiệt độ và giá trị nồng độ khí
đến các cảm biến ảo trên Blynk
Blynk.virtualWrite(V5, analogValue);
Blynk.run(); // Duy trì kết nối và xử lý sự kiện Blynk
}
#include <DHT.h> //Khai báo thư viện
const int quangtroPin = A0;
const int ledPin = 3;
const int analogMQ5 = A1;
float analogValue;
const int DHTPin = 4;
const int DHTTYPE = DHT11;
DHT dht(DHTPin, DHTTYPE);
const int buzzer = 11;
void setup() {
    pinMode(ledPin, OUTPUT); //Đèn led
Serial.begin(9600);
pinMode(analogMQ5, INPUT); //cảm biến khí gas/khói
pinMode(buzzer, OUTPUT); //Còi buzzer
dht.begin();
}
void loop() {
// quang trở
int quangtroValue = analogRead(quangtroPin);
if (quangtroValue < 100) digitalWrite(ledPin, LOW); //Giá trị Analog của
quang trở > 100 thì đèn sáng và ngược lại
else digitalWrite(ledPin, HIGH);
// cảm biến khí gas MQ-5
analogValue = analogRead(analogMQ5);
// Nếu nồng độ gas >= 400ppm thì in ra màn hình "Phát hiện khí gas" + Còi
buzzer sẽ phát ra tiếng và ngược lại.
if (analogValue >= 400) {
Serial.println("Phát hiện gas!");
tone(buzzer, 2000);
delay(1000);
noTone(buzzer);
delay(500);
}
else Serial.println("Không phát hiện gas");
//cảm biến nhiệt DHT11
float doC = dht.readTemperature(); // Đọc nhiệt độ từ cảm biến DHT
Serial.print("nhiệt độ: ");
Serial.println(doC);
if (doC >= 40.0){ //Nếu nhiệt độ trên 40 độ C thì còi sẽ phát ra tiếng
tone(buzzer, 2000);
delay(1000);
noTone(buzzer);
delay(500);
}
delay(500);
}