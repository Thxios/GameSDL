
#ifndef TILEMAP_H_
#define TIMEMAP_H_

#include "includes.h"

class TileMap {

public:
    TileMap(int width, int height);
    ~TileMap();

    void Load();
    void Draw();

private:
    int w, h;

    SDL_Rect srcRect, destRect;
    
    vector<SDL_Texture*> tileTextures;
};


#endif  // TILEMAP_H_

