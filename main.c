#include "config.h"
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (int)SCREEN_WIDTH, (int)SCREEN_HEIGHT, 0);

        if (window != NULL) {

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

            if (renderer != NULL) {

                SDL_bool done = SDL_FALSE;

                while (!done) {
                    SDL_Event event;

                    while (SDL_PollEvent(&event)) {
                        switch (event.type) {
                        case SDL_QUIT:
                            done = SDL_TRUE;
                            break;
                        }
                    }
                }

                if (renderer) {
                    SDL_DestroyRenderer(renderer);
                }
                if (window) {
                    SDL_DestroyWindow(window);
                }
                SDL_Quit();
            }
        }
    }

    return 0;
}
