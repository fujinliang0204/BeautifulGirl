//
//  TollgateScene.h
//  BeautifulGirl
//
//  Created by 付金亮 on 14/10/23.
//
//

#ifndef __BeautifulGirl__TollgateScene__
#define __BeautifulGirl__TollgateScene__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio;

USING_NS_CC;
using namespace ui;
class TollgateScene : public Layer{
    
public:
    
    static Scene* createScene();
    
    CREATE_FUNC(TollgateScene);
    
    virtual bool init();
    
    Button* btn_left;
    
    Button* btn_right;
    
    void moveToLeft(Ref *pSender, Widget::TouchEventType type);
    
    void moveToRight(Ref *pSender, Widget::TouchEventType type);
    
    void moveRight(float dt);
    
    void moveLeft(float dt);
    
    void moveEnd(float dt);
    
    void checkIsFight(float dt);
private:
    
    Armature* m_player;
    Armature* m_monster;

};

#endif /* defined(__BeautifulGirl__TollgateScene__) */
