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
		auto txt = cocos2d::CCLabelBMFont::create("UI", "bigFont.fnt");
		button->addChild(txt);
		txt->setScale(0.9f);
		txt->setPosition(61, 74);
		txt->setColor(cocos2d::ccc3(0, 255, 0));
		bottomMenu->addChild(button);
		button->setScale(0.6f);

		return true;
	}

	void onButtonClick(CCObject* sender) {
		auto notif = Notification::create("Entered the UI Engine!", NotificationIcon::Success, float(3.0f));
		notif->show();
		auto tprm = this->getChildByID("top-right-menu");
		auto ebtn = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
			this,
			menu_selector(MyMenuLayer::onExitButtonClick)
		);

		tprm->addChild(ebtn);
		ebtn->setScale(0.65f);
		ebtn->setPosition(180, 25);
	}

	void onExitButtonClick(CCObject* sender) {
		auto notif2 = Notification::create("Exited the UI Engine!", NotificationIcon::Info, float(3.0f));
		notif2->show();
	};
};

class $modify(MyPauseLayer, PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();
		auto menu = this->getChildByID("right-button-menu");
		if (!menu) return;
		auto spr = CCSprite::createWithSpriteFrameName("GJ_editBtn_001.png");
		spr->setScale(0.6f);
		auto psbtn = CCMenuItemSpriteExtra::create(
			spr, 
			this,
			menu_selector(MyPauseLayer::onButtonClick)
		);
		auto txt = cocos2d::CCLabelBMFont::create("UI", "bigFont.fnt");
		psbtn->addChild(txt);
		txt->setScale(0.5f);
		txt->setPosition(39, 43);
		txt->setColor(cocos2d::ccc3(0, 255, 0));
		menu->addChild(psbtn);
		menu->updateLayout();
	}

	void onButtonClick(CCObject* sender) {
		auto notif = Notification::create("Entered the UI Engine!", NotificationIcon::Success, float(3.0f));
		notif->show();
		auto lbm = this->getChildByID("left-button-menu");
		auto ebtn = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
			this,
			menu_selector(MyPauseLayer::onPauseExit)
		);
		
		lbm->addChild(ebtn);
		ebtn->setScale(0.65f);
		lbm->updateLayout();
		
	}

	void onPauseExit(CCObject* sender) {
		auto notif2 = Notification::create("Exited the UI Engine!", NotificationIcon::Info, float(3.0f));
		notif2->show();
	};
};