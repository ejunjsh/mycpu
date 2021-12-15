/**
 * 该程序用于写入CPU的控制信号。
 * 所有的套件可在benblue.tapbao.com 中获得
 */
#define SHIFT_DATA 2
#define SHIFT_CLK 3
#define SHIFT_LATCH 4
#define EEPROM_D0 5         
#define EEPROM_D7 12
#define WRITE_EN 13

#define HLT 0b1000000000000000  // Halt clock                   HLT信号
#define MI  0b0100000000000000  // Memory address register in   内存地址输入
#define RI  0b0010000000000000  // RAM data in                  内存数据输入
#define RO  0b0001000000000000  // RAM data out                 内存数据输出
#define IO  0b0000100000000000  // Instruction register out     指令寄存器输出
#define II  0b0000010000000000  // Instruction register in      指令寄存器输入
#define AI  0b0000001000000000  // A register in                A寄存器输入
#define AO  0b0000000100000000  // A register out               A寄存器输出
#define EO  0b0000000010000000  // ALU out                      ALU输出
#define SU  0b0000000001000000  // ALU subtract                 减法
#define BI  0b0000000000100000  // B register in                B寄存器输入
#define OI  0b0000000000010000  // Output register in           输出寄存器输入
#define CE  0b0000000000001000  // Program counter enable       程序计数允许
#define CO  0b0000000000000100  // Program counter out          程序计数器输出
#define J   0b0000000000000010  // Jump (program counter in)    程序计数器输入（JUMP）

uint16_t data[] = {
  MI|CO,  RO|II|CE,  0,      0,      0,         0, 0, 0,   // 0000 - NOP
  MI|CO,  RO|II|CE,  IO|MI,  RO|AI,  0,         0, 0, 0,   // 0001 - LDA
  MI|CO,  RO|II|CE,  IO|MI,  RO|BI,  EO|AI,     0, 0, 0,   // 0010 - ADD
  MI|CO,  RO|II|CE,  IO|MI,  RO|BI,  EO|AI|SU,  0, 0, 0,   // 0011 - SUB
  MI|CO,  RO|II|CE,  IO|MI,  AO|RI,  0,         0, 0, 0,   // 0100 - STA
  MI|CO,  RO|II|CE,  IO|AI,  0,      0,         0, 0, 0,   // 0101 - LDI
  MI|CO,  RO|II|CE,  IO|J,   0,      0,         0, 0, 0,   // 0110 - JMP
  MI|CO,  RO|II|CE,  0,      0,      0,         0, 0, 0,   // 0111
  MI|CO,  RO|II|CE,  0,      0,      0,         0, 0, 0,   // 1000
  MI|CO,  RO|II|CE,  0,      0,      0,         0, 0, 0,   // 1001
  MI|CO,  RO|II|CE,  0,      0,      0,         0, 0, 0,   // 1010
  MI|CO,  RO|II|CE,  0,      0,      0,         0, 0, 0,   // 1011
  MI|CO,  RO|II|CE,  0,      0,      0,         0, 0, 0,   // 1100
  MI|CO,  RO|II|CE,  0,      0,      0,         0, 0, 0,   // 1101
  MI|CO,  RO|II|CE,  AO|OI,  0,      0,         0, 0, 0,   // 1110 - OUT
  MI|CO,  RO|II|CE,  HLT,    0,      0,         0, 0, 0,   // 1111 - HLT
};


/*
 *使用移位寄存器输出地址位和outputEnable信号。
 */
void setAddress(int address, bool outputEnable) {
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, (address >> 8) | (outputEnable ? 0x00 : 0x80));
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, address);

  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
  
}


/*
 * 从指定地址的EEPROM读取一个字节。
 */
byte readEEPROM(int address) {
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, INPUT);
  }
  setAddress(address, /*outputEnable*/ true);

  byte data = 0;
  for (int pin = EEPROM_D7; pin >= EEPROM_D0; pin -= 1) {
    data = (data << 1) + digitalRead(pin);
  }
  return data;
}


/*
 * 将字节写入指定地址的EEPROM。
 */
void writeEEPROM(int address, byte data) {
  setAddress(address, /*outputEnable*/ false);
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, OUTPUT);
  }

  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    digitalWrite(pin, data & 1);
    data = data >> 1;
  }
  digitalWrite(WRITE_EN, LOW);
  delayMicroseconds(1);
  digitalWrite(WRITE_EN, HIGH);
  delay(10);
}


/*
 * 读取EEPROM的内容并将其打印到串行监视器。
 */
void printContents() {
  for (int base = 0; base <= 255; base += 16) {
    byte data[16];
    for (int offset = 0; offset <= 15; offset += 1) {
      data[offset] = readEEPROM(base + offset);
    }

    char buf[80];
    sprintf(buf, "%03x:  %02x %02x %02x %02x %02x %02x %02x %02x   %02x %02x %02x %02x %02x %02x %02x %02x",
            base, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7],
            data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);

    Serial.println(buf);
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_CLK, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);
  digitalWrite(WRITE_EN, HIGH);
  pinMode(WRITE_EN, OUTPUT);
  Serial.begin(57600);

  // 写数据
  Serial.print("写 EEPROM");
  writeEEPROM(0, 0);        
  // 将微码的8个高位写到EEPROM的前128个字节中
  for (int address = 0; address < sizeof(data)/sizeof(data[0]); address += 1) {
    writeEEPROM(address, data[address] >> 8);

    if (address % 64 == 0) {
       writeEEPROM(address, data[address] >> 8);
      Serial.print(".");
    }
  }

  // 将微码的8个低位写到EEPROM的前128个字节中
  for (int address = 0; address < sizeof(data)/sizeof(data[0]); address += 1) {
    writeEEPROM(address + 128, data[address]);

    if (address % 64 == 0) {
      writeEEPROM(address + 128, data[address]);
      Serial.print(".");
    }
  }

  Serial.println(" done");


  // 读并打印出EERPROM的内容
  Serial.println("读 EEPROM");
  printContents();
}


void loop() {
  // put your main code here, to run repeatedly:

}
