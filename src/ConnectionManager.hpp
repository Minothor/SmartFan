//
// Created by njboy on 13-08-22.
//

#ifndef SMARTFAN_CONNECTIONMANAGER_HPP
#define SMARTFAN_CONNECTIONMANAGER_HPP

#include "Arduino.h"
#include <ArduinoBLE.h>

class ConnectionManager {

public:
    virtual bool StartPairing();


};
#endif //SMARTFAN_CONNECTIONMANAGER_HPP