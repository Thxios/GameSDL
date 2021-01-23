
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"



GameObject* player;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {}
Game:: ~Game() {}

void Game::Init(const char* title, int x, int y, int w, int h, bool fullScreen) {

    int flags = 0;
    if (fullScreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "SubSystem Initializing..." << endl;

        window = SDL_CreateWindow(title, x, y, w, h, flags);
        if (window) {
            cout << "Window Created..." << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer Created..." << endl;
        }

        isRunning = true;
        
    }
    else {
        isRunning = false;
    }

    player = new GameObject("assets/images/player.png", 0, 100);

    cout << "Game Initialized" << endl;

}

void Game::HandleEvents() {
    
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }

}

void Game::Update() {

    cnt++;

    player->Update();

    // cout << cnt << endl;
}

void Game::Render() {

    SDL_RenderClear(renderer);

    player->Render();

    SDL_RenderPresent(renderer);

}

void Game::Clean() {

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    cout << "Game Cleaned" << endl;

}

