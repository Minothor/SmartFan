//
// Created by njboy on 13-08-22.
//

#ifndef SMARTFAN_FANCONTROLLER_HPP
#define SMARTFAN_FANCONTROLLER_HPP


#include <api/ArduinoAPI.h>

class FanController {

private:
    int outputNum;
    int outputPins[0];

    int updatePinOuts(){
        for(int pinNum : outputPins) {
            pinMode(pinNum, OUTPUT);
        }
        return toggleOutputs(0);
    }

    int toggleOutputs(int level){
        for(int pinNum : outputPins){
            digitalWrite(pinNum, LOW);
        }
        if(!level) return 0;

        digitalWrite(outputPins[level-1], HIGH);
    }

public:
    int setOuputs(int size, int pins[] ){
        int * outputPins = new int[size];
        outputPins = pins;
        outputNum = size;
        return updatePinOuts();
    }
    int setPower(int level){
        if( !outputNum || level > outputNum || level < 0){
            return 0;
        }
        return toggleOutputs(level);
    }

};


#endif //SMARTFAN_FANCONTROLLER_HPP
