#include <SDL3/SDL.h>
#include "window.h"
#include "windowAComplex.h"
#include "render.h"

// Example Code
/*
int main() {
    SDLWindow window("Test", 600, 600);
    SDL_Window* sdlWindow = static_cast<SDL_Window*>(window.getNativeHandle());
    SDLRenderer renderer(sdlWindow);
    SDL_Renderer* sdlRenderer = static_cast<SDL_Renderer*>(renderer.getRenderer());

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }

        // Clear screen (black)
        SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
        SDL_RenderClear(sdlRenderer);

        // Draw a red rectangle
        SDL_SetRenderDrawColor(sdlRenderer, 255, 0, 0, 255);
        SDL_FRect rect = { 100, 100, 200, 150 };
        SDL_RenderFillRect(sdlRenderer, &rect);

        // Update screen
        window.updScreen();
    }
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();

    return 0;
}
*/

int main() {


    int ww = NULL;
    int wh = NULL;

    Window window("Test", 600, 600);
    window.windowSize(&ww, &wh);

    SimpleVertex v1 = { ww/2, wh/2, 255, 0, 0, 1 };
    SimpleVertex v2 = { ww/2+ww/4, wh/2+wh/4, 255, 0, 0, 1 };
    SimpleVertex v3 = { ww/2+ww/4, ww/2, 255, 0, 0, 1 };
    
    window.clear();
    // window.drawTri(v1, v2, v3);
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }
        window.drawGrid(255, 255, 255, 255, 20);
        window.drawLine(300, 300, 580, 460, 255, 255, 255, 255);
        window.updScreen();
    }
    return 0;
}

