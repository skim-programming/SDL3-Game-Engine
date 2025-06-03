#include "render.h"
#include <SDL3/SDL.h>

// Rendering functions
// SDL_RenderClear()	Fill screen with draw color
// SDL_RenderFillRect()	Draw filled rectangle
// SDL_RenderTexture()	Draw a texture
// SDL_SetRenderDrawColor()	Set default color
// SDL_RenderGeometry()	Draw triangles
// This might be for SDL2, check docs for SDL3

struct vertex {
	float x, y;
	float r, g, b, a;
	float u, v;

	vertex() : x(0), y(0), r(0), g(0), b(0), a(0), u(0), v(0) {}

	vertex(const SimpleVertex& sv) : x(sv.x), y(sv.y), r(sv.r), g(sv.g), b(sv.b), a(sv.a), u(0), v(0) {}

	operator SDL_Vertex() const {
		return{
		{ x, y },
		{ r, g, b, a },
		{ u, v }
		};
	}
};

struct Window::Impl {
	SDL_Window* window;
	SDL_Renderer* renderer;
};

Window::Window(const std::string& title, int w, int h) : pImpl(std::make_unique<Impl>()){
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	pImpl->window = SDL_CreateWindow(title.c_str(), w, h, SDL_WINDOW_OPENGL);
	pImpl->renderer = SDL_CreateRenderer(pImpl->window, NULL);	
}

void Window::drawTri(SimpleVertex& sv1, SimpleVertex& sv2, SimpleVertex& sv3) {
	vertex v1 = sv1;
	vertex v2 = sv2;
	vertex v3 = sv3;

	vertex vertices[3] = {v1, v2, v3};
	SDL_RenderGeometry(pImpl->renderer,
		NULL,
		reinterpret_cast<SDL_Vertex*>(vertices),
		3,
		NULL,
		0);
}

void Window::updScreen() {
	SDL_RenderPresent(pImpl->renderer);
}

void Window::windowSize(int* w, int* h) {
	SDL_GetWindowSize(pImpl->window, w, h);
}

void Window::clear() {
	SDL_SetRenderDrawColor(pImpl->renderer, 0, 0, 0, 255); // Set drawing color - used for most/every render operation
	SDL_RenderClear(pImpl->renderer);
}

Window::~Window() = default;
