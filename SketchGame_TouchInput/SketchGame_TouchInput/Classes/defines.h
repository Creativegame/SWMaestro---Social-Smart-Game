//
//  defines.h
//  SketchGame_TouchInput
//
//  Created by Jung Hanter on 12. 9. 1..
//
//

#ifndef SketchGame_TouchInput_defines_h
#define SketchGame_TouchInput_defines_h


#define GAME_FRAME_SPEED 0.15f
#define SPEED_MOUNTAIN 2000
#define SPEED_CLOUD 500

#define MOUNTAIN_ANCOHR_Y -(425.0f/249.0f)

#define HERO_INIT_POS ccp(200,70)
#define HERO_HIDE_DEST_POS ccp(120,70)
#define HERO_HIDE_MID_POS (ccp((HERO_INIT_POS.x+HERO_HIDE_DEST_POS.x)/2, 70))

//몬스터 12프레임에서 전투, 오브제는 15프레임에서 멈춤 -> 3프레임 + 5프레임(주인공숨는시간)
//몬스터 15 - 3 - 5 = 7프레임 차이로 몬스터 생성되야함

// y = x^a, n등분일때 (1/n * M배) = (n/n)의 a값 구하기
// M * (1/n * x0)^a = (x0)^a
// a = log.n.(M) = log(M)/log(n)
// _N_등분일때 _M_배
#define obj_coefficient(_N_,_M_) (float)(log(_M_)/log(_N_))

// y = x^a
//#define



enum GameState { GAMESTATE_RUNNING, GAMESTATE_HIDEWAITING, GAMESTATE_HIDE, GAMESTATE_BATTLE };
enum NowObject { OBJECT_NONE, OBJECT_STONE, OBJECT_GRASS };
enum TextureOrder { ORDER_FARAWAY_MOUNTAIN=0, ORDER_FARAWAY_CLOUD, ORDER_FARWAY_CASTLE,
    ORDER_BACKGROUND, ORDER_OBJECT, ORDER_MONSTER, ORDER_HERO };
enum TagInfo { TAG_NORMAL=0, TAG_TEXTURE, TAG_TEXTURE_BACKGROUND, TAG_TEXTURE_OBJECT,
    TAG_TEXTURE_MONSTER,TAG_TEXTURE_HERO, TAG_ETC };

#endif
