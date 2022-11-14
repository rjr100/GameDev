#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	// Each game object has its own update function
	void Update();
	void Render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

};