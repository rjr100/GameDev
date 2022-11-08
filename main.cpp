#include "SDL.h"
#include "Game.h"

Game* game = nullptr;

int main(int args, char* argsv[])
{
	game = new Game();

	game->init("GameWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
		// handle any user input
		// update all objects
		// render display
	}
	game->clean();

	return 0;
}