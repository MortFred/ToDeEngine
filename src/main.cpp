#include "HelloSDL.h"
#include "HelloCpputest.h"
#include <stdint.h>
#include <SDL2/SDL.h>
#include <tuple>

int main() 
{
    InitGameWindow();
    LoadMedia();
    // SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
    // SDL_UpdateWindowSurface( gWindow );
    SDL_Event e;
        bool quit = false;
        while (!quit){
            while (SDL_PollEvent(&e)){
                if (e.type == SDL_QUIT){
                    quit = true;
                }
                if (e.type == SDL_KEYDOWN){
                    quit = true;
                }
                if (e.type == SDL_MOUSEBUTTONDOWN){
                    quit = true;
                }
            }
        }
    return 1;
}
