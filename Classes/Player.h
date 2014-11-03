//
//  Player.h
//  BeautifulGirl
//
//  Created by 付金亮 on 14/10/29.
//
//

#ifndef __BeautifulGirl__Player__
#define __BeautifulGirl__Player__

#include "Entity.h"

class Player : public Entity{
    
public:
    Player();
    
    ~Player();
    
    CREATE_FUNC(Player);
    
    virtual bool init();
    
    void onBindArmature();
    
    
};

#endif /* defined(__BeautifulGirl__Player__) */
