#include "HelloWorldScene.h"
#include "NewScene.h"
//#include "NewScene2.h"
//#include "NewScene3.h"
#include "Definitions.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "exit.png",
                                           "exit.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'exit.png' and 'exit.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Welcome to menu", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("myprojet/back/image-6.png");
    if (sprite == nullptr)
    {
        problemLoading("'myprojet/back/image-6.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
        // add menu
            // create menu
        auto playItem = MenuItemFont::create("play", CC_CALLBACK_1(HelloWorld::GoToNewScene, this));
        //auto playItem = MenuItemFont::create("play", CC_CALLBACK_1(HelloWorld::GoToNewScene2, this));
        //auto playItem = MenuItemFont::create("play", CC_CALLBACK_1(HelloWorld::GoToNewScene3, this));
        //auto menu_item_2 = MenuItemFont::create("Menu", CC_CALLBACK_1(HelloWorld::Menu, this));
       // playItem->setPosition(Point(visibleSize.width / 4 + origin.x, visibleSize.height / 3 + origin.y));


        auto* menu = Menu::create(playItem, NULL);

        //menu->setPosition(Point::ZERO);

        menu->alignItemsVertically();
        this->addChild(menu);
    }
    return true;
}
void HelloWorld::GoToNewScene(cocos2d::Ref* pSender)
{
    auto scene = NewScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
    //auto scene = NewScene::createScene();
    //Director::getInstance()->pushScene(scene);
}
/*
void HelloWorld::GoToNewScene2(cocos2d::Ref* pSender)
{
    auto scene = NewScene2::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
    //auto scene = NewScene::createScene();
    //Director::getInstance()->pushScene(scene);
}
void HelloWorld::GoToNewScene3(cocos2d::Ref* pSender)
{
    auto scene = NewScene3::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
    //auto scene = NewScene::createScene();
    //Director::getInstance()->pushScene(scene);
}

*/

/*void HelloWorld::Menu(cocos2d::Ref* pSender)
{
    CCLOG("Menu");
    //auto scene = Scene::create();
    //Director::getInstance()->replaceScene(scene);
}*/



void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
