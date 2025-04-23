#include "MyLayer.hpp"

using namespace cocos2d;

using geode::Anchor;
using geode::AxisAlignment;

bool MyLayer::init() {
	if (!CCLayer::init()) return false;

	this->setKeypadEnabled(true);

	m_bg = CCSprite::create("GJ_gradientBG.png");

	m_bg->setAnchorPoint({0.f, 0.f});
	m_bg->setPosition({-5.f, -5.f});

	auto winSize = CCDirector::sharedDirector()->getWinSize();
	auto bgSize = m_bg->getContentSize();
	m_bg->setScaleX((winSize.width + 10.f) / bgSize.width);
	m_bg->setScaleY((winSize.height + 10.f) / bgSize.height);
	m_bg->setColor({0, 102, 255});
	this->addChild(m_bg);


	m_contentLayer = CCLayer::create();
	m_contentLayer->setLayout(geode::AnchorLayout::create());
	m_contentLayer->setAnchorPoint({0.f, 0.f});
	this->addChild(m_contentLayer);

	m_scrollLayer = geode::ScrollLayer::create({winSize.width - 150.f, winSize.height - 100.f});
	m_scrollLayer->ignoreAnchorPointForPosition(false);
	m_contentLayer->addChildAtPosition(m_scrollLayer, Anchor::Center);

	m_scrollbar = geode::Scrollbar::create(m_scrollLayer);
	m_contentLayer->addChildAtPosition(m_scrollbar, Anchor::Right, {-50.f, 0.f});

	m_scrollLayer->m_contentLayer->setLayout(geode::RowLayout::create()
		->setAxisAlignment(AxisAlignment::Start)
		->setCrossAxisAlignment(AxisAlignment::End)
		->setGap(10.f)
		->setGrowCrossAxis(true)
	);


	// add stuff to the scroll layer

	if (m_scrollLayer->m_contentLayer->getContentHeight() < m_scrollLayer->getContentHeight()) {
		auto diff = m_scrollLayer->getContentHeight() - m_scrollLayer->m_contentLayer->getContentHeight();
		m_scrollLayer->m_contentLayer->setContentHeight(m_scrollLayer->getContentHeight());
		for (auto child : geode::cocos::CCArrayExt<CCNode*>(m_scrollLayer->m_contentLayer->getChildren()))
			child->setPositionY(child->getPositionY() + diff);
	}
	m_scrollLayer->scrollToTop();


	m_btnMenu = CCMenu::create();
	m_contentLayer->addChild(m_btnMenu);

	m_backBtn = CCMenuItemSpriteExtra::create(
		CCSprite::createWithSpriteFrameName(
			fmt::format("GJ_arrow_0{}_001.png", rand() % 3).c_str()
		),
		this, menu_selector(MyLayer::onBack)
	);
	m_backBtn->setAnchorPoint({0.f, 1.f});
	m_btnMenu->addChildAtPosition(m_backBtn, Anchor::TopLeft, {10.f, -10.f});

	m_bg->setID("background");
	m_btnMenu->setID("button-menu");
	m_backBtn->setID("back-button");
	m_contentLayer->setID("content-layer");
	m_scrollLayer->setID("scroll-layer");
	m_scrollbar->setID("scrollbar");
	this->setID("layer"_spr);

	return true;
}

void MyLayer::onBack(CCObject*) {
	CCDirector::get()->replaceScene(CCTransitionFade::create(0.5, MenuLayer::scene(false)));
}

void MyLayer::keyBackClicked() {
	onBack(nullptr);
}

MyLayer* MyLayer::create() {
	auto ret = new MyLayer();
	if (ret->init()) {
		ret->autorelease();
		return ret;
	}

	delete ret;
	return nullptr;
}
