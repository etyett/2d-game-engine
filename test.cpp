#include <SDL2/SDL.h>

#undef main

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;
    const Uint8* key = SDL_GetKeyboardState(NULL);
    bool run = true;
    SDL_Rect rect;
    rect.w = 100;
    rect.h = 100;
    rect.x = 0;
    rect.y = 0;
    while(run) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                run = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 126, 211, 0, 255);
        SDL_RenderClear(renderer);
        if(key[SDL_SCANCODE_W]) {
            rect.y -= 5;
        }
        else if(key[SDL_SCANCODE_A]) {
            rect.x -= 5;
        }
        else if(key[SDL_SCANCODE_S]) {
            rect.y += 5;
        }
        else if(key[SDL_SCANCODE_D]) {
            rect.x += 5;
        }
        SDL_SetRenderDrawColor(renderer, 139, 0, 139, 255);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}