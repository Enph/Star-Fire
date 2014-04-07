//
//  enemy.cpp
//  Star Fire
//
//  Created by La Li Lu Le Lo on 2014-04-02.
//  Copyright (c) 2014 Eric Boisvert. All rights reserved.
//

#include "enemy.h"

using namespace std;



//----------------------Constructor-------------------------
enemy::enemy()
{
    this -> hp = 100;
    this -> shield = 100;
    this -> attackDamage = 10;
    this -> bombs = 3;
    
    this -> enemyXpos = 2.0f;
    this -> enemyYpos = 5.0f;
    this -> enemyZpos = 140.0f;
}


//------------------------Getters----------------------------
int enemy::getHp()
{
    return hp;
    
}

int enemy::getShield()
{
    return shield;
}

int enemy::getAttackDamage()
{
    return attackDamage;
}

int enemy::getBombs()
{
    return bombs;
}

int enemy::getEnemyXpos()
{
    return enemyXpos;
}

int enemy::getEnemyYpos()
{
    return enemyYpos;
}

int enemy::getEnemyZpos()
{
    return enemyZpos;
}

//------------------------Setters----------------------------


void enemy::setXcoord(float coord)
{
    bool is_positive = coord > 0;
    //bool is_negative = coord < 0;
    //bool is_zero = coord == 0;
    
    if(enemyXpos >= -3 && enemyXpos <= 3)
    {
        
        if(is_positive)
        {
            enemyXpos += 1.0f;
        }
        else
        {
            enemyXpos -= 1.0f;
        }
        
    }
    
    if (enemyXpos <= -3) {
        enemyXpos = -3;
    }
    
    if (enemyXpos >= 3) {
        enemyXpos = 3;
    }
    
}

void enemy::setYcoord(float coord)
{
    bool is_positive = coord < 0;
    
    if(enemyYpos >= 3 && enemyYpos <= 8)
    {
        
        if(!is_positive)
        {
            enemyYpos += 1.0f;
        }
        else
        {
            enemyYpos -= 1.0f;
        }
        
    }
    
    if (enemyYpos >= 8) {
        enemyYpos = 8;
    }
    
    if (enemyYpos <= 3) {
        enemyYpos = 3;
    }
    
}

void enemy::setZcoord(float coord)
{
    bool is_positive = coord > 0;
    //bool is_negative = coord < 0;
    //bool is_zero = coord == 0;
    
    if(!is_positive)
    {
        enemyZpos += coord;
    }
    else
    {
        enemyZpos -= coord;
    }
    
}

void enemy::setHp(int setHP)
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

void enemy::setShield(int setSHIELD)
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


void enemy::setAttackDamage(int damage)
{
    if (damage >=0) {
        attackDamage += damage;
    }
    else
    {
        attackDamage -= damage;
    }
    
}

void enemy::setBombs(int inventory)
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

void enemy::resetZcoord()
{
    enemyZpos = 145.0f;
    
}





