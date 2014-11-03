//
//  Background.h
//  BeautifulGirl
//
//  Created by 付金亮 on 14/10/23.
//
//

#ifndef __BeautifulGirl__Background__
#define __BeautifulGirl__Background__

#include "cocos2d.h"

USING_NS_CC;
class BackgroundLayer : public Layer  {
    
public:
    
    BackgroundLayer();
    ~BackgroundLayer();
    
    CREATE_FUNC(BackgroundLayer);
    virtual bool init();
    void logic(int type);

private:
    Sprite* bg_sprite1;
    Sprite* bg_sprite2;
    
};

#endif /* defined(__BeautifulGirl__Background__) */
