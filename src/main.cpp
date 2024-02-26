#include <cocos2d.h>
#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GJPromoPopup.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/modify/GJMoreGamesLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <string>

using namespace geode::prelude;
using namespace cocos2d;
using namespace std;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        CCSprite* litespr = CCSprite::createWithSpriteFrameName("GJ_lite_001.png");

        CCSprite* maintitle = static_cast<CCSprite*>(this->getChildByID("main-title"));
        auto maintitlexpos = maintitle->getPositionX();
        auto maintitleypos = maintitle->getPositionY();

        litespr->setPosition(ccp(maintitlexpos + 149, maintitleypos - 32));
        litespr->setZOrder(2);
        litespr->setID("lite-button");


        auto hideornot = Mod::get()->getSettingValue<bool>("hide-lite-spr");

        litespr->setVisible(!hideornot);


        this->addChild(litespr);

        return true;
    }
};

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        CCMenu* rightSideMenu = static_cast<CCMenu*>(this->getChildByID("right-side-menu"));

        if (rightSideMenu) {
            CCMenuItemSpriteExtra* dailychest = static_cast<CCMenuItemSpriteExtra*>(rightSideMenu->getChildByID("daily-chest-button"));

            if (dailychest) {
                CCSprite* freekeveks = CCSprite::createWithSpriteFrameName("GJ_freeStuffBtn_001.png");
                dailychest->setNormalImage(freekeveks);
            }
        }

        return true;
    }
};

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        CCMenu* MainMenu = static_cast<CCMenu*>(this->getChildByID("main-menu"));

            CCMenuItemSpriteExtra* editbtn = static_cast<CCMenuItemSpriteExtra*>(MainMenu->getChildByID("editor-button"));

            CCSprite* fullbtn = CCSprite::createWithSpriteFrameName("GJ_fullBtn_001.png");
            editbtn->setNormalImage(fullbtn);

        return true;
    }
};

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        CCMenu* moregamesmenu = static_cast<CCMenu*>(this->getChildByID("more-games-menu"));

        if (moregamesmenu) {
            CCMenuItemSpriteExtra* moregamesbtn = static_cast<CCMenuItemSpriteExtra*>(moregamesmenu->getChildByID("more-games-button"));

            if (moregamesbtn) {
                CCSprite* freekeveks = CCSprite::createWithSpriteFrameName("GJ_freeLevelsBtn_001.png");
                moregamesbtn->setNormalImage(freekeveks);
            }
        }

        return true;
    }
};

class $modify(GJMoreGamesLayer) {
    void customSetup() {
        GJMoreGamesLayer::customSetup();
        #ifndef GEODE_IS_ANDROID


        CCLayer* cclayer = dynamic_cast<CCLayer*>(getChildren()->objectAtIndex(0));


        CCSprite* gjmpromo = CCSprite::create("promo_gjm-hd.png"_spr);
        CCSprite* gjzpromo = CCSprite::create("promo_gjz-hd.png"_spr);
        CCSprite* gjwpromo = CCSprite::create("promo_gjw-hd.png"_spr);
        CCLabelBMFont* easports = CCLabelBMFont::create("this bad design is fixed in the full version of Geometry Dash Lite.", "bigFont.fnt");

        CCLabelBMFont* wgat = dynamic_cast<CCLabelBMFont*>(cclayer->getChildren()->objectAtIndex(4));
        


        gjzpromo->setPosition(ccp(283, 219));
        gjwpromo->setPosition(ccp(283, 127));
        gjmpromo->setPosition(ccp(283, 34));
        gjzpromo->setScale(2.01f);
        gjmpromo->setScale(2.01f);
        gjwpromo->setScale(2.01f);
        wgat->setVisible(false);
        easports->setScale(0.4f);
        easports->setPosition(283.5, 308);
        easports->setID("easports");


        cclayer->addChild(gjzpromo);
        cclayer->addChild(gjwpromo);
        cclayer->addChild(gjmpromo);
        cclayer->addChild(easports);

        #endif
    }
};


class $modify(PlayLayer) {
    bool init(GJGameLevel* p0, bool p1, bool p2) {
        if (!PlayLayer::init(p0, p1, p2))
        return false;

        UILayer*  uilayer = static_cast<UILayer*>(this->getChildByID("UILayer"));
        CCLabelBMFont* label = CCLabelBMFont::create("GDLite. free trial", "bigFont.fnt");

        label->setPosition(ccp(41, 9));
        label->setScale(0.225f);

        auto hidegdlitewmornot = Mod::get()->getSettingValue<bool>("hide-gdlite-watermark");

        label->setVisible(!hidegdlitewmornot);

        uilayer->addChild(label);
    return true;
    }
};