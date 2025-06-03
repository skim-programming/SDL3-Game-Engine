#pragma once
#ifndef WINDOW_ABSTRACT_C_H
#define WINDOW_ABSTRACT_C_H

// Version of window.h with abstraction

#include <SDL3/SDL.h>
#include <string>
#include <stdexcept>

class IWindow {
public:
	virtual ~IWindow() = default;
	virtual void* getNativeHandle() const = 0;
};

class IRenderer {
public:
	virtual ~IRenderer() = default;
	virtual void* getRenderer() = 0;
};

class SDLWindow : public IWindow {
	SDL_Window* window = nullptr;
public:
	SDLWindow(const std::string title, int width, int height) {
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_OPENGL);
	}
	void* getNativeHandle() const override {
		return static_cast<void*>(window);
	}
	~SDLWindow() override {
		if (window) SDL_DestroyWindow(window);
		SDL_Quit();
	}
};

class SDLRenderer : public IRenderer {
	SDL_Renderer* renderer = nullptr;
public:
	SDLRenderer(SDL_Window* window) {
		renderer = SDL_CreateRenderer(window, NULL);
	}
	void* getRenderer() {
		return static_cast<void*>(renderer);
	}
};

#endif