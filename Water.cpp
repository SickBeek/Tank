#include "Water.h"

Water::Water()
{
}

Water::~Water()
{
}

bool Water::init(Vec2 position)
{
	if (!Sprite::init())
	{
		return false;
	}

	m_sprite = Sprite::create("Chapter12/tank/tile.png", Rect(0, 0, 16, 16));

	this->addChild(m_sprite);
	m_sprite->setPosition(Vec2::ZERO);

	this->setPosition(position);
	m_rect = Rect(this->getPositionX() - 8, this->getPositionY() - 8, 16, 16);

	return true;
}

Water* Water::create(Vec2 position)
{
	Water* pRet = new(std::nothrow) Water();
	if (pRet && pRet->init(position))
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

void Water::Blast()
{
	this->setVisible(false);   // ×©¿éÏûÊ§
	this->removeFromParent();
}