#include <Arduino.h>
#include "ButtonManager.hpp"
#include "ConnectionManager.hpp"
#include "FanController.hpp"
#include "SensorManager.hpp"
void setup() {
// write your initialization code here
ButtonManager buttons = new ButtonManager();
ConnectionManager ble = new ConnectionManager();
FanController fan = new FanController();

buttons.addTarget(0x1, fan.setPower, 0);
buttons.addTarget(0x2, fan.setPower, 1);
buttons.addTarget(0x4, fan.setPower, 2);
buttons.addTarget(0x8, fan.setPower, 3);
buttons.addTarget(0x9, ble.StartPairing, 3);
}

void loop() {
// write your code here
}