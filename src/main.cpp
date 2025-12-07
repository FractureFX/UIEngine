#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/Notification.hpp>

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
		auto notif = Notification::create("Entered the UI Engine!", NotificationIcon::Success, float(3.0f));
		notif->show();
	}
};

class $modify(MyPauseLayer, PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();
		auto menu = this->getChildByID("right-button-menu");
		if (!menu) return;
		auto spr = CCSprite::createWithSpriteFrameName("GJ_editBtn_001.png");
		spr->setScale(0.65f);
		auto psbtn = CCMenuItemSpriteExtra::create(
			spr, 
			this,
			menu_selector(MyPauseLayer::onButtonClick)
		);
		menu->addChild(psbtn);
		menu->updateLayout();
	}

	void onButtonClick(CCObject* sender) {
		auto notif = Notification::create("Entered the UI Engine!", NotificationIcon::Success, float(3.0f));
		notif->show();
	}
};