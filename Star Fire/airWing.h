//
//  airWing.h
//  Star Fire
//
//  Created by La Li Lu Le Lo on 2014-04-01.
//  Copyright (c) 2014 Eric Boisvert. All rights reserved.
//

#ifndef __Star_Fire__airWing__
#define __Star_Fire__airWing__

#include <iostream>



class airWing
{
private:
    
    int hp = 0;
    int shield = 0;
    int attackDamage = 0;
    int bombs = 0;
    float airwingXpos = 0.0f;
    float airwingYpos = 5.0f;
    float airwingZpos = 140.0f;
    

public:
    
    airWing(int cHp, int cShield, int cAttackDamage, int cBombs)
    {
        
        setHp(cHp);
        setShield(cShield);
        setAttackDamage(cAttackDamage);
        setBombs(cBombs);
    
    }
    
    airWing();
    
    int getHp();
    int getShield();
    int getAttackDamage();
    int getBombs();
    
    int getAirWingXpos();
    int getAirWingYpos();
    int getAirWingZpos();

    
    void setHp(int setHP);
    void setShield(int setSHIELD);
    void setAttackDamage(int power);
    void setBombs(int inventory);
    
    void setXcoord(float coord);
    void setYcoord(float coord);
    void setZcoord(float coord);
    
    void resetZcoord();
    
    
};



#endif /* defined(__Star_Fire__airWing__) */
