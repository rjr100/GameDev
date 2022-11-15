#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"

Map* map;
SDL_Renderer* Game::renderer = nullptr;

Manager manager;

auto& player(manager.addEntity());


Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem Initialised!..." << std::endl;

		window = SDL_CreateWindow("GameWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;
	} else {
		isRunning = false;
	}

	
	// map = new Map();
	player.addComponent<PositionComponent>();
	player.addComponent<SpriteComponent>("RawAssets/Riko.png");

	//playerTex = TextureManager::LoadTexture("RawAssets/Riko.png", renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		//case SDL_WINDOW_FULLSCREEN
		default:
			break;
	}

}

void Game::update() 
{
	//manager.refresh();
	manager.update();

}

void Game::render()
{
	SDL_RenderClear(renderer);
	// This is where we would add stuff to renderer
	// 
	// Using painter's algorithm
	// Stuff added first is in the background
	// 
	// map->DrawMap(); 

	//SDL_RenderCopy(renderer, playerTex, NULL, &destR); // pass(renderer, texture you want, src rectange, dst rectangle

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}
