//
//  Entity.cpp
//  BeautifulGirl
//
//  Created by 付金亮 on 14/10/29.
//
//

#include "Entity.h"

Entity::Entity(){
    m_bindArmature = nullptr;
    m_isDead = false;
    m_sprite = nullptr;
}

Entity::~Entity(){
    
}

void Entity::bindSprite(Sprite* sprite){
    if(this->m_sprite != NULL){
        m_sprite->removeFromParentAndCleanup(true);
    }
    
    this->m_sprite = sprite;
    this->addChild(sprite);
    onBindSprite();
}

Sprite* Entity::getSprite(){
    return this->m_sprite;
}

void Entity::onBindSprite(){
}

void Entity::bindArmature(Armature *armature){
    
    if (this->m_bindArmature != nullptr) {
        m_bindArmature->removeFromParentAndCleanup(true);
    }
    
    this->m_bindArmature = armature;
    this->addChild(armature);
    onBindArmature();
}

Armature* Entity::getBindArmature(){
    return this->m_bindArmature;
}

void Entity::onBindArmature(){
}

void Entity::hurtMe(int iHurtValue ) {
    
    int iCurHP = getiHP();//当前血条
    int iAfterHP = iCurHP - iHurtValue; //剩余血条
    
    onHurt(iHurtValue);
    
    if(iAfterHP > 0) {
        setiHP(iAfterHP);
    }
    else {
        m_isDead = true;
        onDead();
    }
    
}

bool Entity::isDead(){
    return m_isDead;
}

void Entity::onDead(){
    
}

void Entity::onHurt(int iHurtValue){
    
}