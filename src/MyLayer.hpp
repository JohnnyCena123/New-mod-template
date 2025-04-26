#pragma once
#include <Geode/Geode.hpp>

using namespace cocos2d;

class MyLayer : public CCLayer {
protected:
	CCSprite* m_bg;

	CCLayer* m_contentLayer;

	geode::ScrollLayer* m_scrollLayer;
	geode::Scrollbar* m_scrollbar;

	CCMenu* m_btnMenu;
	CCMenuItemSpriteExtra* m_backBtn;
	bool init() override;
	void onBack(CCObject*);

	void keyBackClicked() override;
public:
	static MyLayer* create();
};
