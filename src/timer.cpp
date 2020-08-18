#pragma once

#include "timer.h"

void Timer::start_timer() {
	t_i = std::chrono::high_resolution_clock::now();
	_running = true;
}

void Timer::stop_timer() {
	t_f = std::chrono::high_resolution_clock::now();
	_running = false;
	_ready = false;
}

void Timer::calculate_time() {
	t_d = std::chrono::duration_cast<std::chrono::duration<double>>(t_f - t_i);
}

void Timer::prime_timer() {
	_ready = true;
}

double Timer::get_time() {
	return t_d.count();
}

void Timer::initialize() {
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
			else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && _ready == false) {
				prime_timer();
				std::cout << "Timer has been primed" << std::endl;
			}

			else if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE && _ready == true) {
				start_timer();
				std::cout << "Timer has been started" << std::endl;
			}

			else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && _running == true) {
				stop_timer();
				calculate_time();
				std::cout << "Time has been stopped" << std::endl;
				std::cout << "Time: " << get_time() << " seconds." << std::endl;
			}
		}
	}
}