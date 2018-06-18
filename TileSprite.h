#ifndef __TILE_SPRITE_H__
#define __TILE_SPRITE_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace cocos2d;

class TileSprite : public Sprite
{
public:
	TileSprite();
	~TileSprite();
	static TileSprite* create(Vec2 position, int type);
	virtual bool init(Vec2 position, int type);
	void Blast();
	int getType();
	// get
	Rect getRect() { return m_rect; };

private:
	Sprite * m_sprite;  // ¾«Áé
	Rect m_rect;       // °üÎ§¿ò
	int m_type;
};

#endif