
#ifndef GAME_H_
#define GAME_H_

#include "includes.h"


class Game {

public:
    Game();
    ~Game();

    void Init(const char* title, int x, int y, int w, int h, bool fullScreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    bool IsRunning() { return isRunning; }

    static SDL_Renderer* renderer;


private:
    int cnt = 0;
    bool isRunning;
    SDL_Window* window;
};

#endif  // GAME_H_ 
