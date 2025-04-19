// clangd automatically adds those when i use tab to autocomplete so who am i to argue
#include "Geode/binding/CCMenuItemSpriteExtra.hpp"
#include "Geode/binding/GJAccountManager.hpp"
#include "Geode/cocos/cocoa/CCObject.h"
#include "Geode/utils/cocos.hpp"

#include "MyLayer.hpp"

using namespace cocos2d;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {

    bool init() {
        if (!MenuLayer::init()) return false;
	auto btn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_playBtn2_001"),
            this, menu_selector(MyMenuLayer::onMyLayer)
        );

        auto menu = this->getChildByID("bottom-menu");
        menu->addChild(btn);
	menu->updateLayout();

	btn->setID("button"_spr);

        return true;
    }

    void onMyLayer(CCObject*) {
        (void)geode::cocos::switchToScene(MyLayer::create());
    }
};
