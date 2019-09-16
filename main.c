#include "config.h"
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {

        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer((int)SCREEN_WIDTH, (int)SCREEN_HEIGHT, 0, &window, &renderer) == 0) {
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

    return 0;
}
