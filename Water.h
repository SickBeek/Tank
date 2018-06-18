#ifndef __Water_H__
#define __Water_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace cocos2d;

class Water : public Sprite
{
public:
	Water();
	~Water();
	static Water* create(Vec2 position);
	virtual bool init(Vec2 position);
	void Blast();

	// get
	Rect getRect() { return m_rect; };

private:
	Sprite * m_sprite;  // ×©¿é¾«Áé
	Rect m_rect;       // °üÎ§¿ò
};

#endif