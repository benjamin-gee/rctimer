#include <iostream>
#include <SDL.h>
#include <chrono>
#include <ctime>
#include "timer.h"

int main(int argc, char* argv[]) {

	SDL_Window* window = nullptr;
	SDL_Surface* windowSurface = nullptr;
	Timer _timer;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialize. SDL Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Video could not initialize. SDL Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	window = SDL_CreateWindow("RCTIMER v 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	std::cout << "Welcome to the Rubiks Cube Timer" << std::endl;
	_timer.initialize();
	std::cout << "Thanks for playing" << std::endl;
	SDL_Quit();

	return 0;
}