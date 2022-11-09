
#include "Game.h"

Game* game = nullptr;

int main(int args, char* argsv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS; // Max time between frames
	Uint32 frameStart;
	int frameTime;


	game = new Game();

	game->init("GameWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
		// handle any user input
		// update all objects
		// render display
	}
	game->clean();

	return 0;
}