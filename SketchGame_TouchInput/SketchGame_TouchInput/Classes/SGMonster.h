//
//  SGMonster.h
//  SketchGame_TouchInput
//
//  Created by Jung Hanter on 12. 9. 1..
//
//

#ifndef __SketchGame_TouchInput__SGMonster__
#define __SketchGame_TouchInput__SGMonster__

#include "cocos2d.h"

using namespace cocos2d;

enum SGAttackDirection { ATK_DIR_UP, ATK_DIR_DOWN, ATK_DIR_LEFT, ATK_DIR_RIGHT };

struct SGAttackAction {
    int atkDir;
    CCActionInterval* act_attack;
};

//attack 메서드에서 반환용 구조체. 공격력과 공격방향이 담겨있음
struct SGAttackInfo {
    int atk;
    int atkDir;
};

enum SGMonsterType { MONSTER_TYPE_SPIDER=0, MONSTER_TYPE_NUMBER };

class SGMonster : public CCObject {
public:
    void appear();  //몬스터 출혈 시작
    void beginBattle(); //몬스터 배틀모드
    bool endBattle();   //true면 몬스터 죽음
    void confirmBattlePos();
    
    SGAttackInfo attack();   //return now atkDir & atk
    void defend(int damage);
    void die();
    
    void pauseSchedulerAndActions();
    void resumeSchedulerAndActions();
    
    int getType();
    
    void resetStatus(int hp, int atk);
    void upgradeStatus(float upHpRate, float upAtkRate);
    
private:
    int selectAttackDirection();
    
private:
    int type;
    int maxHP, nowHP;
    int atk;
    
    CCSprite* monsterSprite;
    CCActionInterval* act_run, *act_wait, *act_defend, *act_die;
    
    int numAttacks;
    SGAttackAction* act_attack;  //몬스터 공격 배열 (1~4);

private:
    SGMonster(int type, int hp, int atk, const CCPoint* const movePoints, const int nPoints, CCLayer* const parent);
    CCLayer* const parentLayer;
    
public:
    ~SGMonster();
    static SGMonster* create(int type, int hp, int atk, const CCPoint* const movePoints, const int nPoints,
                             CCLayer* const parent);
};



#endif /* defined(__SketchGame_TouchInput__SGMonster__) */
