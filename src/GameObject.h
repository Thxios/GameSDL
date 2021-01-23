
#ifndef GAMEOBJ_H_
#define GAMEOBJ_H_

#include "Game.h"

class GameObject {

public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:
    int xPos;
    int yPos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;

};


#endif  // GAMEOBJ_H_
