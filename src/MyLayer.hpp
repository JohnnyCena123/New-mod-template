#pragma once
#include <Geode/Geode.hpp>

using namespace prelude;

class MyLayer : public CCLayer {
protected:
	CCSprite* m_bg;

	CCLayer* m_contentLayer;

	ScrollLayer* m_scrollLayer;
	Scrollbar* m_scrollbar;

	CCMenu* m_btnMenu;
	CCMenuItemSpriteExtra* m_backBtn;
	bool init() override;
	void onBack(CCObject*);

	void keyBackClicked() override;
public:
	static MyLayer* create();
};
