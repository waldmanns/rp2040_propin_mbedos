#include <Arduino.h>
#include <pins_arduino.h>
#include <mbed.h>
#include <rtos.h>
#include <PinNames.h>

//defining interrupts on pins ------------------------------------------------------------------------------------------------------------------------------
mbed::InterruptIn edgeDetect_ch1(p25); //D2
mbed::InterruptIn edgeDetect_ch2(p15); //D3
mbed::InterruptIn edgeDetect_ch3(p16); //D4
mbed::InterruptIn edgeDetect_ch4(p17); //D5
mbed::InterruptIn edgeDetect_ch5(p18); //D6
//END

//defining common variables for prop channel ------------------------------------------------------------------------------------------------------------------------------
struct channel {
  int32_t begin;
  int32_t end;
  float prop;
  mbed::Timer timer;
};
//END

//allocating prop channel variables ------------------------------------------------------------------------------------------------------------------------------
channel ch1;
channel ch2;
channel ch3;
channel ch4;
channel ch5;
//END

//allocating edge detection functions ------------------------------------------------------------------------------------------------------------------------------
void edgeRise_ch1(void);
void edgeFall_ch1(void);

void edgeRise_ch2(void);
void edgeFall_ch2(void);

void edgeRise_ch3(void);
void edgeFall_ch3(void);

void edgeRise_ch4(void);
void edgeFall_ch4(void);

void edgeRise_ch5(void);
void edgeFall_ch5(void);
//END

void setup() {
//interrupts functions binding ------------------------------------------------------------------------------------------------------------------------------
  edgeDetect_ch1.rise(mbed::callback(edgeRise_ch1));
  edgeDetect_ch1.fall(mbed::callback(edgeFall_ch1));

  edgeDetect_ch2.rise(mbed::callback(edgeRise_ch2));
  edgeDetect_ch2.fall(mbed::callback(edgeFall_ch2));

  edgeDetect_ch3.rise(mbed::callback(edgeRise_ch3));
  edgeDetect_ch3.fall(mbed::callback(edgeFall_ch3));

  edgeDetect_ch4.rise(mbed::callback(edgeRise_ch4));
  edgeDetect_ch4.fall(mbed::callback(edgeFall_ch4));

  edgeDetect_ch5.rise(mbed::callback(edgeRise_ch5));
  edgeDetect_ch5.fall(mbed::callback(edgeFall_ch5));
}

//interrupts edges detection ------------------------------------------------------------------------------------------------------------------------------
void edgeRise_ch1(void) {
    ch1.timer.reset();
    ch1.timer.start();
    ch1.begin = ch1.timer.elapsed_time().count();
}

void edgeFall_ch1(void) {
    ch1.end = ch1.timer.elapsed_time().count();
    ch1.timer.stop();
    ch1.prop = ch1.end - ch1.begin;
}

void edgeRise_ch2(void) {
    ch2.timer.reset();
    ch2.timer.start();
    ch2.begin = ch2.timer.elapsed_time().count();
}

void edgeFall_ch2(void) {
    ch2.end = ch2.timer.elapsed_time().count();
    ch2.timer.stop();
    ch2.prop = ch2.end - ch2.begin;
}

void edgeRise_ch3(void) {
    ch3.timer.reset();
    ch3.timer.start();
    ch3.begin = ch3.timer.elapsed_time().count();
}

void edgeFall_ch3(void) {
    ch3.end = ch3.timer.elapsed_time().count();
    ch3.timer.stop();
    ch3.prop = ch3.end - ch3.begin;
}

void edgeRise_ch4(void) {
    ch4.timer.reset();
    ch4.timer.start();
    ch4.begin = ch4.timer.elapsed_time().count();
}

void edgeFall_ch4(void) {
    ch4.end = ch4.timer.elapsed_time().count();
    ch4.timer.stop();
    ch4.prop = ch4.end - ch4.begin;
}

void edgeRise_ch5(void) {
    ch5.timer.reset();
    ch5.timer.start();
    ch5.begin = ch5.timer.elapsed_time().count();
}

void edgeFall_ch5(void) {
    ch5.end = ch5.timer.elapsed_time().count();
    ch5.timer.stop();
    ch5.prop = ch5.end - ch5.begin;
}
//END


void loop() {
  //use chX.prop to access the signal
  delay(1);
}
