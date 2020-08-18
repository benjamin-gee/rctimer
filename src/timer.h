#pragma once
#include <SDL.h>
#include <chrono>
#include <ctime>
#include <iostream>

class Timer {
public:
	void start_timer();
	void stop_timer();
	void calculate_time();
	void prime_timer();
	double get_time();
	void initialize();
private:
	int quit = 0;
	SDL_Event event;
	bool _ready = false;
	bool _running = false;
	std::chrono::high_resolution_clock::time_point t_i;
	std::chrono::high_resolution_clock::time_point t_f;
	std::chrono::duration<double> t_d;
};