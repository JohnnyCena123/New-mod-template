#include <Geode/Geode.hpp>

#include "MyLayer.hpp"

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {

	bool init() {
		if (!MenuLayer::init()) return false;
		auto spr = CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png");
		spr->setScale(.65f);
		auto btn = CCMenuItemSpriteExtra::create(
			spr, this, menu_selector(MyMenuLayer::onMyLayer)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(btn);
		menu->updateLayout();

		btn->setID("button"_spr);

		return true;
	}

	void onMyLayer(CCObject*) {
		(void)switchToScene(MyLayer::create());
	}
};
