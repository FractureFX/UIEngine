#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto bottomMenu = this->getChildByID("bottom-menu");
		auto button = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_editBtn_001.png"),
			this,
			menu_selector(MyMenuLayer::onButtonClick)
		);

		bottomMenu->addChild(button);
		button->setScale(0.6f);

		return true;
	}

	void onButtonClick(CCObject* sender) {
		FLAlertLayer::create("The Engine is WIP", "Still coding this lol", "OK")->show();
	}
};