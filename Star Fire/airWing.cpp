//
//  airWing.cpp
//  Star Fire
//
//  Created by La Li Lu Le Lo on 2014-04-01.
//  Copyright (c) 2014 Eric Boisvert. All rights reserved.
//

#include "airWing.h"
using namespace std;



//----------------------Constructor-------------------------
airWing::airWing()
{
    this -> hp = 100;
    this -> shield = 100;
    this -> attackDamage = 10;
    this -> bombs = 3;
    
    this -> airwingXpos = 0.0f;
    this -> airwingYpos = 5.0f;
    this -> airwingZpos = 0.0f;
}


//------------------------Getters----------------------------
int airWing::getHp()
{
    return hp;

}

int airWing::getShield()
{
    return shield;
}

int airWing::getAttackDamage()
{
    return attackDamage;
}

int airWing::getBombs()
{
    return bombs;
}

int airWing::getAirWingXpos()
{
    return airwingXpos;
}

int airWing::getAirWingYpos()
{
    return airwingYpos;
}

int airWing::getAirWingZpos()
{
    return airwingZpos;
}

//------------------------Setters----------------------------


void airWing::setXcoord(float coord)
{
    bool is_positive = coord > 0;
    //bool is_negative = coord < 0;
    //bool is_zero = coord == 0;
    
   // if(airwingXpos >= -3 && airwingXpos <= 3)
    //{
    
        if(is_positive)
        {
            airwingXpos += 1.0f;
        }
        else
        {
            airwingXpos -= 1.0f;
        }
        
    //}
    /*
    if (airwingXpos <= -3) {
        airwingXpos = -3;
    }
    
    if (airwingXpos >= 3) {
        airwingXpos = 3;
    }
     */

}

void airWing::setYcoord(float coord)
{
    bool is_positive = coord < 0;
    
   // if(airwingYpos >= 3 && airwingYpos <= 8)
    //{
        
        if(!is_positive)
        {
            airwingYpos += 1.0f;
        }
        else
        {
            airwingYpos -= 1.0f;
        }
        
    //}
    /*
    if (airwingYpos >= 8) {
        airwingYpos = 8;
    }
    
    if (airwingYpos <= 3) {
        airwingYpos = 3;
    }*/
    
}

void airWing::setZcoord(float coord)
{
    bool is_positive = coord > 0;
    //bool is_negative = coord < 0;
    //bool is_zero = coord == 0;
    
    if(!is_positive)
    {
        airwingZpos += coord;
    }
    else
    {
        airwingZpos -= coord;
    }
    
}

void airWing::setHp(int setHP)
{
    if (setHP >= 0)// add hp
    {
        hp += setHP;
    }
    else // subtract hp aka take damage
    {
        hp -= setHP;
    }
}

void airWing::setShield(int setSHIELD)
{
    if (setSHIELD >= 0)
    {
        shield += setSHIELD;
    }
    else
    {
        shield -= setSHIELD;
    }
}


void airWing::setAttackDamage(int damage)
{
    if (damage >=0) {
         attackDamage += damage;
    }
    else
    {
        attackDamage -= damage;
    }
    
}

void airWing::setBombs(int inventory)
{
    if (inventory >= 0)
    {
        bombs += inventory;
    }
    else
    {
        bombs -= inventory;
    }

}

void airWing::resetZcoord()
{
    airwingZpos = 145.0f;

}





