# mycpu

八位cpu, 4个寄存器，16条指令

## 准备

### 材料

按这个这个在淘宝上买

| 数量 | 名字                   |
| ---- | ---------------------- |
| 15   | 面包板                 |
| 1    | 5v 1a 电源和线         |
| 1    | 电子铜线（规格22AWG）  |
| 10   | 1kΩ 电阻               |
| 9    | 10kΩ 电阻              |
| 1    | 100kΩ 电阻             |
| 24   | 220Ω 电阻              |
| 1    | 1MΩ 电阻               |
| 1    | 1MΩ 电位器             |
| 6    | 0.01µF 电容            |
| 16   | 0.1µF 电容             |
| 1    | 1µF 电容               |
| 4    | 555定时芯片            |
| 2    | 74LS00 (NAND 与非门)   |
| 1    | 74LS02 (NOR 或非门)    |
| 5    | 74LS04 (NOT 非门)      |
| 3    | 74LS08 (AND 与门)      |
| 1    | 74LS32 (OR 或门)       |
| 1    | 74LS76 (JK触发器)      |
| 2    | 74LS86 (XOR异或门)     |
| 1    | 74LS138 (3位译码电路)  |
| 1    | 74LS139 (2位译码电路)  |
| 4    | 74LS157 (二选一电路)   |
| 2    | 74LS161 (4位计数器)    |
| 8    | 74LS173 (4位寄存器)    |
| 2    | 74LS189 (64bit内存)    |
| 6    | 74LS245 (三态门)       |
| 1    | 74LS273 (8位D触发器)   |
| 2    | 74LS283 (4 位加法器)   |
| 2    | 74HC595(8位移位寄存器) |
| 3    | 28C16 EEPROM           |
| 3    | 按钮开关（自锁）       |
| 3    | 轻触开关（6mm）        |
| 1    | 8位拨码开关            |
| 1    | 四位拨码开关           |
| 44   | 红色 LED               |
| 8    | 黄色 LED               |
| 12   | 绿色 LED               |
| 21   | 蓝色 LED               |
| 4    | 共阴数码管（一位）     |
| 1    | Arduino Nano           |

### 注意事项

#### 面包版

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/10.jpeg" width="50%" height="50%">

#### 电源
如果家有苹果的五福一安电源就够了，再淘宝买个usb转公线就可以了

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/01.jpeg" width="50%" height="50%">

#### 电阻
淘宝上买一袋袋的电阻，里面个种阻值都有

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/02.jpeg" width="50%" height="50%">

#### 电位器
下图那种就可以了，但是这种扭起来不算很顺，你可以看看其他类似上面有颗比较大一点的旋钮的，这样扭起来好扭

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/12.jpeg" width="50%" height="50%">

#### 电容
这个买103，104，105的电容就好，分别代表0.01µF ，0.1µF ，1µF ,淘宝也是一袋袋买的

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/03.jpeg" width="50%" height="50%">

#### 电线相关
买个剥线钳，因为电线是AWG 22 规格，所以要买能剥这种线的

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/04.jpeg" width="50%" height="50%">

电线记得买 _单芯_ 的ok线，规格是AWG22.最好买各种颜色的，好看哈哈😄

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/13.jpeg" width="50%" height="50%">

如果需要买点面包版跳线，用来做实验好

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/14.jpeg" width="50%" height="50%">

#### 芯片
上面芯片的数量是搭建cpu用到的芯片数量，如果是那种只有一个的芯片，最好买多个，这样你可以在有问题的时候，能够确定是不是芯片的问题

#### 按钮开关（自锁）

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/06.jpeg" width="50%" height="50%">

#### 轻触开关

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/07.jpeg" width="50%" height="50%">

#### 拨码开关

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/11.jpeg" width="50%" height="50%">

#### LED
淘宝买一袋袋的LED，各种颜色都有。

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/09.jpeg" width="50%" height="50%">


#### 数码管
买这种引脚在下面的，好插在面包版

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/05.jpeg" width="50%" height="50%">

#### Arduino Nano
已焊接针脚，带usb线

<img src="https://github.com/ejunjsh/mycpu/raw/main/images/08.jpeg" width="50%" height="50%">

## 视频

一个cpu基本有几个组件拼接起来的，所以视频在每个组件开始搭建之前都会做一些实验，上面材料不包括这些实验用到的材料，所以如果你想做实验，那就再买一些

### 中文

[https://www.bilibili.com/video/BV1BJ411R7s5](https://www.bilibili.com/video/BV1BJ411R7s5)

### 英文

[https://eater.net/8bit](https://eater.net/8bit)
