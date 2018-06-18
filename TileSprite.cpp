#include "TileSprite.h"
#include "Global.h"
TileSprite::TileSprite()
{
}

TileSprite::~TileSprite()
{
}

bool TileSprite::init(Vec2 position, int type)
{
	if (!Sprite::init())
	{
		return false;
	}
	m_type = type;
		
	m_sprite = Sprite::create("Chapter12/tank/tile.png", Rect(type*16, 0, 16, 16));

	this->addChild(m_sprite);
	m_sprite->setPosition(Vec2::ZERO);

	this->setPosition(position);
	m_rect = Rect(this->getPositionX() - 8, this->getPositionY() - 8, 16, 16);

	return true;
}

TileSprite* TileSprite::create(Vec2 position, int type)
{
	TileSprite* pRet = new(std::nothrow) TileSprite();
	if (pRet && pRet->init(position,type))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

void TileSprite::Blast()
{
	this->setVisible(false);   //ÏûÊ§
	this->removeFromParent();
}
int TileSprite::getType()
{
	return m_type;
}
;
