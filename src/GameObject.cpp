
#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* textureSheet, int x, int y) {
    objTexture = TextureManager::LoadTexture(textureSheet);

    xPos = x;
    yPos = y;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 16;
    srcRect.h = 16;

    destRect.x = x;
    destRect.y = y;
    destRect.w = 64;
    destRect.h = 64;
}

void GameObject::Update() {
    xPos++;

    destRect.x = xPos;
    destRect.y = yPos;
}

void GameObject::Render() {

    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

