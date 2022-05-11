#include "HelloSDL.h"
#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Global variables, to be changed later
SDL_Window* mainWindow = NULL;
//A surface object contains pixel data and rendering data. By default CPU generated
SDL_Surface* screenSurface = NULL;
SDL_Surface* helloWorld = NULL;

// int main( int argc, char* args[] )
bool InitGameWindow()
{
    std::cout << "Initializing game window" << std::endl;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    //Create window
    mainWindow = SDL_CreateWindow("SDL Tutorial", 
                                    SDL_WINDOWPOS_UNDEFINED, 
                                    SDL_WINDOWPOS_UNDEFINED, 
                                    SCREEN_WIDTH, 
                                    SCREEN_HEIGHT, 
                                    SDL_WINDOW_SHOWN);
    if(mainWindow == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    //Get mainWindow surface
    screenSurface = SDL_GetWindowSurface(mainWindow);
    return true;
}

bool LoadMedia()
{
    std::string imagePath;
    imagePath.append(std::getenv("PWD"));
    imagePath.append("/media/Morten_headshot.bmp");
    std::cout<<imagePath<<std::endl;

    helloWorld = SDL_LoadBMP("media/Morten_headshot.bmp");
    if(helloWorld == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "/media/Morten_headshot.bmp", SDL_GetError());
        return false;
    }
    return true;
}

void CloseGameWindow()
{
    return;
}

    //         //Fill the surface white
    //         SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
    //         //Update the surface
    //         SDL_UpdateWindowSurface( mainWindow );

    //         SDL_Event e;
    //         bool quit = false;
    //         while (!quit){
    //             while (SDL_PollEvent(&e)){
    //                 if (e.type == SDL_QUIT){
    //                     quit = true;
    //                 }
    //                 if (e.type == SDL_KEYDOWN){
    //                     quit = true;
    //                 }
    //                 if (e.type == SDL_MOUSEBUTTONDOWN){
    //                     quit = true;
    //                 }
    //             }
    //         }
    //     }
    // }
    //     //Destroy mainWindow
    // SDL_DestroyWindow( mainWindow );

    // //Quit SDL subsystems
    // SDL_Quit();

    // return true;
    