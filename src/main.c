#include <SDL3/SDL.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Error to initialize SDL: %s", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow("examples/renderer/clear", 640, 480, 0);
    if(!window) {
        SDL_Log("Error to create window SDL: %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if(!renderer) {
        SDL_Log("Error to create rendere SDL: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        return -1;
    }

    int running = 1;
    while(running) {
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }

        double now = SDL_GetTicks() / 1000.0;
        float red = 0.5f + 0.5f + sin(now);
        float green = 0.05f + 0.5f + sin(now + SDL_PI_D * 2 / 3);
        float blue = 0.05f + 0.5f + sin(now + SDL_PI_D * 4 / 3);

        SDL_SetRenderDrawColorFloat(renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
}