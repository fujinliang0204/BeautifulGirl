//
//  TollgateScene.cpp
//  BeautifulGirl
//
//  Created by 付金亮 on 14/10/23.
//
//

#include "TollgateScene.h"
#include "BackgroundLayer.h"

#define BACKGROUNDTAG 1

Scene* TollgateScene::createScene(){
    
    auto scene = Scene::create();
    
    auto tollgateScene = TollgateScene::create();
    
    scene->addChild(tollgateScene,1);
    return scene;
}

bool TollgateScene::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    
    
    
    auto backgroundLayer = BackgroundLayer::create();
    
    this->addChild(backgroundLayer,0,BACKGROUNDTAG);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    ArmatureDataManager::getInstance()->addArmatureFileInfo("girl.ExportJson");
    
    m_player = Armature::create("girl");
    m_player->setPosition(Vec2(visibleSize.width*0.2, visibleSize.height*0.5));
    m_player->getAnimation()->play("loading");
    
    
    
    ArmatureDataManager::getInstance()->addArmatureFileInfo("MonsterEnemy.ExportJson");
    
    m_monster = Armature::create("MonsterEnemy");
    m_monster->setPosition(Vec2(visibleSize.width*0.8, visibleSize.height*0.5));
    m_monster->getAnimation()->play("run");
    m_monster->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-20,0))));
    
    btn_left = Button::create("arrow.png");
    btn_left->setScaleX(-1.0f);
    btn_left->setPosition(Vec2(visibleSize.width*0.1, visibleSize.height*0.1));
    btn_left->addTouchEventListener(this, toucheventselector(TollgateScene::moveToLeft));
    
    btn_right = Button::create("arrow.png");
    btn_right->setPosition(Vec2(visibleSize.width*0.2+btn_right->getContentSize().width/2, visibleSize.height*0.1));
    btn_right->addTouchEventListener(this, toucheventselector(TollgateScene::moveToRight));
    
    this->addChild(btn_left);
    this->addChild(btn_right);
    this->addChild(m_player);
    this->addChild(m_monster);
    
    this->schedule(schedule_selector(TollgateScene::checkIsFight));
    return true;
}


void TollgateScene::moveToLeft(Ref *pSender, Widget::TouchEventType type)
{
    
    
    switch (type)
    {
        case Widget::TouchEventType::BEGAN:
            this->schedule(schedule_selector(TollgateScene::moveLeft),0.3f);
            
            break;
            
        case Widget::TouchEventType::MOVED:
            break;
            
        case Widget::TouchEventType::ENDED:
            this->scheduleOnce(schedule_selector(TollgateScene::moveEnd),0.5f);
            break;
            
        case Widget::TouchEventType::CANCELED:
            this->scheduleOnce(schedule_selector(TollgateScene::moveEnd),0.5f);
            break;
            
        default:
            break;
    }
}

void TollgateScene::moveToRight(Ref *pSender, Widget::TouchEventType type)
{
    
    switch (type)
    {
        case Widget::TouchEventType::BEGAN:
            this->schedule(schedule_selector(TollgateScene::moveRight),0.3f);
            break;
            
        case Widget::TouchEventType::MOVED:
            log("moveToRight MOVED");
            
            break;
            
        case Widget::TouchEventType::ENDED:
            
            this->scheduleOnce(schedule_selector(TollgateScene::moveEnd),0.5f);
            break;
            
        case Widget::TouchEventType::CANCELED:
            
            this->scheduleOnce(schedule_selector(TollgateScene::moveEnd),0.5f);
            break;
            
        default:
            break;
    }
}

void TollgateScene::moveRight(float dt){
    auto m_background = (BackgroundLayer*)getChildByTag(BACKGROUNDTAG);
    m_background->logic(2);
    m_player->getAnimation()->play("run");
}

void TollgateScene::moveLeft(float dt){
    auto m_background = (BackgroundLayer*)getChildByTag(BACKGROUNDTAG);
    m_background->logic(1);
    m_player->getAnimation()->play("run");
}

void TollgateScene::moveEnd(float dt){
    m_player->getAnimation()->play("loading");
    this->unschedule(schedule_selector(TollgateScene::moveRight));
    this->unschedule(schedule_selector(TollgateScene::moveLeft));

}

void TollgateScene::checkIsFight(float dt){
    
    auto posA = m_player->getPosition();
    
    auto posB = m_monster->getPosition();
    
    float subPos = posB.x - posA.x;
    
    log("posA %f",posA.x);
    
    float attackPos = m_monster->getContentSize().width/4+m_player->getContentSize().width/2;
    
    if (subPos < attackPos) {
        log("fighting.......");
        this->unschedule(schedule_selector(TollgateScene::checkIsFight));
        m_monster->stopAllActions();
        m_monster->getAnimation()->play("attack");
        m_player->getAnimation()->play("attack");
    }
    
    
}



