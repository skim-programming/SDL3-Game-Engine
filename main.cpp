#include <SDL3/SDL.h>
#include "window.h"

// Example Code

int main() {
    easyWindow window("test");
    SDL_Renderer* renderer = window.getRenderer();

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }

        // Clear screen (black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw a red rectangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_FRect rect = { 100, 100, 200, 150 };
        SDL_RenderFillRect(renderer, &rect);

        // Update screen
        SDL_RenderPresent(renderer);
    }

    window.easyCleanup();
    return 0;
}
