//
//  Entity.h
//  BeautifulGirl
//
//  Created by 付金亮 on 14/10/29.
//
//

#ifndef __BeautifulGirl__Entity__
#define __BeautifulGirl__Entity__


#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocostudio;

class Entity : public Node{
    
public:
    
    Entity();
    ~Entity();
    
    //绑定精灵
    void bindSprite(Sprite* sprite);
    
    virtual void onBindSprite();
    
    //获得绑定的精灵
    Sprite* getSprite();
    
    //绑定动画
    void bindArmature(Armature* armature);
    
    //onBindArmature
    virtual void onBindArmature();
    
    //获取绑定的动画
    Armature* getBindArmature();
    
    //受伤
    void hurtMe(int iHurtValue);
    
    virtual void onHurt(int iHurtValue);
    
    //死亡
    bool isDead();
    
    virtual void onDead();
    
private:
    
    Sprite* m_sprite;
    
    Armature* m_bindArmature;
    
    bool m_isDead; //是否死亡
    
    CC_SYNTHESIZE(int, m_ID, ID);	//id
    CC_SYNTHESIZE(int, m_iHP, iHP); // HP
    CC_SYNTHESIZE(int, m_iDefense, iDefense);   //防御
    CC_SYNTHESIZE(std::string, m_bullet, bulletId);   //子弹id
    CC_SYNTHESIZE(float, m_attackspeed, attackspeed);//攻击速度
    CC_SYNTHESIZE(bool, m_isArrive, isArrive);
    CC_SYNTHESIZE(bool, m_isFight, isFight);
    CC_SYNTHESIZE(int, m_type, iType);//类别
    
    
};

#endif /* defined(__BeautifulGirl__Entity__) */
