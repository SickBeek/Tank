#include "AppDelegate.h"
#include "GameClient.h"


USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
	if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) {
		if (!glview) {
			glview = GLViewImpl::createWithRect("Contra", Rect(0, 0, 960, 640), 1.f);
			director->setOpenGLView(glview);
		}

		// turn on display FPS
		director->setDisplayStats(true);
	}
	else if (!glview)
	{
		glview = GLViewImpl::create("Contra");
		director->setOpenGLView(glview);
	}
	// end of CC_PLATFORM_WIN32
	//glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::EXACT_FIT);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene =GameClient::createScene();    // 创建相应章节的场景进行测试

    // run
    director->runWithScene(scene);
	
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
