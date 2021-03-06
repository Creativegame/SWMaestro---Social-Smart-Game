LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := helloworld/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/SketchGameScene.cpp \
                   ../../Classes/SGBackground.cpp \
                   ../../Classes/SGHero.cpp \
                   ../../Classes/SGHidableObject.cpp \
                   ../../Classes/SGMonster.cpp \
                   ../../Classes/SketchTitleScene.cpp \
                   ../../Classes/SGSaveData.cpp \
                   ../../Classes/SGSignScene.cpp \
                   ../../Classes/SGSound.cpp \
                   ../../Classes/SGOptionScene.cpp \
                   ../../Classes/SGUpgradeScene.cpp \
                   ../../Classes/SGRankingScene.cpp \


                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) $(call import-module,cocos2dx)
