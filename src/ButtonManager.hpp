//
// Created by njboy on 13-08-22.
//

#ifndef SMARTFAN_BUTTONMANAGER_HPP
#define SMARTFAN_BUTTONMANAGER_HPP

#include <sys/unistd.h>
#include "Arduino.h"
#include "Array.h"
// This defines a type for
// function prototypes
typedef int (*Func)(int);

class ButtonManager {

private:
    int inputNum;
    int inputPins[0];
    bool buttonCooldown = false;

    Array<int, 0> funcKeys;
    Array<Func, 0> funcValues;
    Array<int, 0> funcInputs;


    int updatePins(){
        for(int pinNum : inputPins) {
            pinMode(pinNum, INPUT_PULLUP);
        }
        return 0;
    }

    void buttonPressed(){
        if(buttonCooldown) return;
        buttonCooldown = true;
        sleep(1);
        int buttons = 0x0;
        int offset = 0;
        for(int pin  : inputPins) {
            int pinValue = analogRead(pin);
            int mask = (1 << offset);
            if (pinValue < HIGH) buttons |= mask;
            else buttons &= ~mask;
            offset += 1;
        }

        return;
    }

public:
    int setInputs(int size, int pins[] ){
        int * inputPins = new int[size];
        inputPins = pins;
        inputNum = size;
        return updatePins();
    }

    int setSink(int pin){
        pinMode(pin, INPUT_PULLDOWN);
        attachInterrupt(digitalPinToInterrupt(pin), buttonPressed, RISING);
    }

    int runTarget(int keyIn){
        int index = 0;
        for (int key : funcKeys){
            if (key == keyIn) return funcValues[index](funcInputs[index]);
            index++;
        }
        return 1;
    }

    void addTarget (int newKey, Func &newTarget){
        funcKeys.push_back(newKey);
        funcValues.push_back(newTarget);
    }

};


#endif //SMARTFAN_BUTTONMANAGER_HPP
