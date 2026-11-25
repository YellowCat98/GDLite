#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>

using namespace geode::prelude;

void addLiteSprite(MenuLayer* menuLayer) {
    auto litespr = CCSprite::createWithSpriteFrameName("GJ_lite_001.png");

    auto maintitle = static_cast<CCSprite*>(menuLayer->getChildByID("main-title"));
    auto maintitlexpos = maintitle->getPositionX();
    auto maintitleypos = maintitle->getPositionY();

    litespr->setPosition({maintitlexpos + 149, maintitleypos - 32});
    litespr->setZOrder(2);
    litespr->setID("lite-button");

    menuLayer->addChild(litespr);
}

void replaceRightBtn(MenuLayer* menuLayer) {
    auto rightSideMenu = static_cast<CCMenu*>(menuLayer->getChildByID("right-side-menu"));

    if (rightSideMenu) {
        auto dailychest = static_cast<CCMenuItemSpriteExtra*>(rightSideMenu->getChildByID("daily-chest-button"));

        if (dailychest) {
            auto freekeveks = CCSprite::createWithSpriteFrameName("GJ_freeStuffBtn_001.png");
            dailychest->setNormalImage(freekeveks);
        }
    }
}

void replaceCreatorSprite(MenuLayer* menuLayer) {
    auto MainMenu = static_cast<CCMenu*>(menuLayer->getChildByID("main-menu"));

    auto editbtn = static_cast<CCMenuItemSpriteExtra*>(MainMenu->getChildByID("editor-button"));

    auto fullbtn = CCSprite::createWithSpriteFrameName("GJ_fullBtn_001.png");
    editbtn->setNormalImage(fullbtn);
}

void doMoreGamesStuff(MenuLayer* menuLayer) {
    auto moregamesmenu = static_cast<CCMenu*>(menuLayer->getChildByID("more-games-menu"));

    if (moregamesmenu) {
        auto moregamesbtn = static_cast<CCMenuItemSpriteExtra*>(moregamesmenu->getChildByID("more-games-button"));

        if (moregamesbtn) {
            auto freekeveks = CCSprite::createWithSpriteFrameName("GJ_freeLevelsBtn_001.png");
            moregamesbtn->setNormalImage(freekeveks);
        }
   }
}

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // doing it like this cause im a bit lazy to just drag and drop everything into the same function!
        // me in 2024 used to make a separate init hook for this, so GDLite was initializing 4 of the same hooks!

        addLiteSprite(this);
        replaceRightBtn(this);
        replaceCreatorSprite(this);
        doMoreGamesStuff(this);

        return true;
    }
};

$on_game(Loaded) {
    auto overlay = OverlayManager::get();

    auto label = geode::Label::create("GDLite. Free Trial.", "bigFont.fnt");
    label->setScale(0.225f);
    label->setID("gd-lite-wm"_spr);


    float xOffset = 38.0f;
    float yOffset = 5.0f;
    switch (Mod::get()->getSettingValue<int>("gdlite-wm-pos")) {
        case 0: label->setVisible(false); // only doing it like this so if anymod finds my node cute and tries to get it they can get it
        case 1: overlay->addChildAtPosition(label, Anchor::BottomLeft, {xOffset, yOffset}, false); break;
        case 2: overlay->addChildAtPosition(label, Anchor::BottomRight, {-xOffset, yOffset}, false); break;
        case 3: overlay->addChildAtPosition(label, Anchor::TopLeft, {xOffset, -yOffset}, false); break;
        case 4: overlay->addChildAtPosition(label, Anchor::TopRight, {-xOffset, -yOffset}, false); break;
    }
}


class $modify(LoadingLayer) {
    bool init(bool p0) {
        if (!LoadingLayer::init(p0)) return false;

        if (Mod::get()->getSettingValue<bool>("lite-spr-onloadinglayer")) {
            auto litespr = CCSprite::createWithSpriteFrameName("GJ_lite_001.png");

            auto maintitle = static_cast<CCSprite*>(this->getChildByID("gd-logo"));
            auto maintitlexpos = maintitle->getPositionX();
            auto maintitleypos = maintitle->getPositionY();

            litespr->setPosition({maintitlexpos + 149, maintitleypos - 32});

            this->addChild(litespr);            
        }


        return true;
    }

};
