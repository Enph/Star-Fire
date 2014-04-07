//
//  enemy.h
//  Star Fire
//
//  Created by La Li Lu Le Lo on 2014-04-02.
//  Copyright (c) 2014 Eric Boisvert. All rights reserved.
//

#ifndef __Star_Fire__enemy__
#define __Star_Fire__enemy__

#include <iostream>


class enemy
{
private:
    
    int hp = 0;
    int shield = 0;
    int attackDamage = 0;
    int bombs = 0;
    float enemyXpos = 2.0f;
    float enemyYpos = 5.0f;
    float enemyZpos = 130.0f;
    
public:
    
    enemy(int cHp, int cShield, int cAttackDamage, int cBombs)
    {
        
        setHp(cHp);
        setShield(cShield);
        setAttackDamage(cAttackDamage);
        setBombs(cBombs);
        
    }
    
    enemy();
    
    int getHp();
    int getShield();
    int getAttackDamage();
    int getBombs();
    
    int getEnemyXpos();
    int getEnemyYpos();
    int getEnemyZpos();
    
    
    void setHp(int setHP);
    void setShield(int setSHIELD);
    void setAttackDamage(int power);
    void setBombs(int inventory);
    
    void setXcoord(float coord);
    void setYcoord(float coord);
    void setZcoord(float coord);
    
    void resetZcoord();
    
    
};




#endif /* defined(__Star_Fire__enemy__) */
