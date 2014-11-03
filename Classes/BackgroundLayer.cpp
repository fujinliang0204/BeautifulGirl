//
//  Background.cpp
//  BeautifulGirl
//
//  Created by 付金亮 on 14/10/23.
//
//

#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer(){
    
}

BackgroundLayer::~BackgroundLayer(){
    
}

bool BackgroundLayer::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    bg_sprite1 = Sprite::create("background.png");
    bg_sprite1->setPosition(visibleSize.width/2,visibleSize.height/2);
    
    bg_sprite2 = Sprite::create("background2.png");
    bg_sprite2->setPosition(visibleSize.width*3/2,visibleSize.height/2);
    
    
    this->addChild(bg_sprite1);
    this->addChild(bg_sprite2);
    
    return true;
}

void BackgroundLayer::logic(int type){
    int posX1 = bg_sprite1->getPositionX();	//背景地图1的X坐标
    int posX2 = bg_sprite2->getPositionX();	//背景地图2的X坐标
    
    log("posX1 %d",posX1);
    
    int iSpeed = 20;	//地图滚动速度
    if(type == 2){
        /* 两张地图向左滚动（两张地图是相邻的，所以要一起滚动，否则会出现空隙） */
        posX1 -= iSpeed;
        posX2 -= iSpeed;
    }else{
        /* 两张地图向左滚动（两张地图是相邻的，所以要一起滚动，否则会出现空隙） */
        posX1 += iSpeed;
        posX2 += iSpeed;
    }

    
    
    
    bg_sprite1->setPositionX(posX1);
    bg_sprite2->setPositionX(posX2);
}

