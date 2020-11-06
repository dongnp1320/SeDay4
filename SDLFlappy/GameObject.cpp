#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* texturesheet, int x, int y)
{
	xpos = x;
	ypos = y;
	objTexture = TextureManager::LoadTexture(texturesheet);
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	xpos++;
	ypos++;

	//srcRect.h = 64;
	//srcRect.w = 64;
	//srcRect.x = 0;
	//srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 100;
	destRect.h = 100;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}
