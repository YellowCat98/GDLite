#include <cocos2d.h>
#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/modify/GJPromoPopup.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/modify/GJMoreGamesLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <string>

using namespace geode::prelude;
using namespace cocos2d;

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

/*
class $modify(GJMoreGamesLayer) {
    void customSetup() {
        GJMoreGamesLayer::customSetup();
        #ifndef GEODE_IS_MOBILE


        CCLayer* cclayer = dynamic_cast<CCLayer*>(getChildren()->objectAtIndex(0));


        auto hidemgmm = Mod::get()->getSettingValue<bool>("remove-more-games-menu-modification");

        if (!hidemgmm) {

        CCSprite* gjmpromo = CCSprite::create("promo_gjm.png"_spr);
        CCSprite* gjzpromo = CCSprite::create("promo_gjz.png"_spr);
        CCSprite* gjwpromo = CCSprite::create("promo_gjw.png"_spr);
        CCLabelBMFont* easports = CCLabelBMFont::create("this bad design is fixed in the full version of Geometry Dash Lite.", "bigFont.fnt");

        CCLabelBMFont* wgat = dynamic_cast<CCLabelBMFont*>(cclayer->getChildren()->objectAtIndex(4));
        


        gjzpromo->setPosition(ccp(283, 219));
        gjwpromo->setPosition(ccp(283, 127));
        gjmpromo->setPosition(ccp(283, 34));
        gjzpromo->setScale(1.01f);
        gjmpromo->setScale(1.01f);
        gjwpromo->setScale(1.01f);
        wgat->setVisible(false);
        easports->setScale(0.4f);
        easports->setPosition(283.5, 308);
        easports->setID("easports");


        cclayer->addChild(gjzpromo);
        cclayer->addChild(gjwpromo);
        cclayer->addChild(gjmpromo);
        cclayer->addChild(easports);
        }

        #endif
    }
};
*/

class $modify(PlayLayer) {
    bool init(GJGameLevel* p0, bool p1, bool p2) {
        if (!PlayLayer::init(p0, p1, p2))
        return false;

        UILayer*  uilayer = static_cast<UILayer*>(this->getChildByID("UILayer"));
        CCLabelBMFont* label = CCLabelBMFont::create("GDLite. free trial", "bigFont.fnt");

        switch (Mod::get()->getSettingValue<int64_t>("gdlite-wm-pos"))
        {
            case 0:
            /* hide label */
            label->setVisible(false);
            break;

            case 1:
            /* bottom left */
            label->setPosition(41, 10);
            break;

            case 2:
            /* bottom right */
            label->setPosition(525, 10);
            break;

            case 3:
            /* top left */
            label->setPosition(41, 310);
            break;

            case 4:
            /* top right */
            label->setPosition(525, 310);
            break;
        }

        label->setScale(0.225f);

        uilayer->addChild(label);
    return true;
    }
};

class $modify(LoadingLayer) {
    bool init(bool p0) {
        if (!LoadingLayer::init(p0))
            return false;
        if (Mod::get()->getSettingValue<bool>("lite-spr-onloadinglayer")) {
            CCSprite* litespr = CCSprite::createWithSpriteFrameName("GJ_lite_001.png");

            CCSprite* maintitle = static_cast<CCSprite*>(this->getChildByID("gd-logo")); /* i love you robtop */
            auto maintitlexpos = maintitle->getPositionX();
            auto maintitleypos = maintitle->getPositionY();

            litespr->setPosition(ccp(maintitlexpos + 149, maintitleypos - 32));

            this->addChild(litespr);            
        }


        return true;
    }
};

class $modify(MyCreatorLayer, CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init())
            return false;

        if (auto menu = typeinfo_cast<CCMenu*>(this->getChildByID("creator-buttons-menu"))) {
            if (auto creator = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID("create-button"))) { creator->setColor({128, 128, 128}); }
            if (auto map = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID("map-button"))) { map->setColor({128, 128, 128}); }
            if (auto gauntlets = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID("gauntlets-button"))) { gauntlets->setColor({128, 128, 128}); }
            if (auto packs = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID("map-packs-button"))) { packs->setColor({128, 128, 128}); }
            if (auto search = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID("search-button"))) { search->setColor({128, 128, 128}); }
        }

        return true;
    }
};