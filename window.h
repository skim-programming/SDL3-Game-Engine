#pragma once
#ifndef EASY_WINDOW_H
#define EASY_WINDOW_H

#include <SDL3/SDL.h>
#include <string>
#include <stdexcept>

// Easy Window Initialization

class easyWindow {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

public:
	easyWindow(const std::string& windowTitle) {
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		const SDL_DisplayMode* display = SDL_GetDesktopDisplayMode(SDL_GetPrimaryDisplay());
		window = SDL_CreateWindow(windowTitle.c_str(), 
			display->w, 
			display->h, 
			SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
		if (!window) {
			throw std::runtime_error("Window creation failed: " + std::string(SDL_GetError()));
		}
		renderer = SDL_CreateRenderer(window, NULL);
	}

	SDL_Renderer* getRenderer() {
		return renderer;
	}

	SDL_Window* getWindow() {
		return window;
	}

	void easyCleanup() {
		if(renderer)
		{
			SDL_DestroyRenderer(renderer);
			renderer = nullptr;
		}
		if(window)
		{
			SDL_DestroyWindow(window);
			window = nullptr;
		}
		SDL_Quit();
	}

	~easyWindow() {
		easyCleanup();
	}
};

#endif