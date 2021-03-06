#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Key.h"
#include "Game.h"

enum keyState
{
    NORMAL
} states;

enum EnemyAnims
{
    STAND
};


Key::~Key()
{
    if (sprite != NULL) {
        delete sprite;
        sprite = nullptr;
    }
}

void Key::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, const glm::ivec2& posInicial, int id)
{
    states = NORMAL;
    got = false;
    spritesheet.loadFromFile("images/Key.png", TEXTURE_PIXEL_FORMAT_RGBA);
    sprite = Sprite::createSprite(glm::ivec2(16, 16), glm::vec2(1.f, 1.f), &spritesheet, &shaderProgram);
    sprite->setNumberAnimations(1);

    sprite->setAnimationSpeed(STAND, 1);
    sprite->addKeyframe(STAND, glm::vec2(1.f, 0.f));

    sprite->changeAnimation(0);
    tileMapDispl = tileMapPos;
    ID = id;
    sprite->setPosition(posInicial);
}

void Key::update(int deltaTime)
{
    sprite->update(deltaTime);
    posAnt = posIni;
    switch (states) {
        case NORMAL: {
            if (map->checkIfPlayer(posIni, glm::ivec2(-10, 32))) {
                map->clearPosition(ID);
                got = true;
                Game::instance().playSound("music/KeyEffect.wav");
            }
        } break;
    }
    sprite->setPosition(glm::vec2(float(tileMapDispl.x + posIni.x), float(tileMapDispl.y + posIni.y)));
    if (!got) map->updatePositionTile(posIni, glm::ivec2(32, 32), posAnt, ID);
}

void Key::render()
{
    sprite->render();
}

void Key::setTileMap(TileMap* tileMap)
{
    map = tileMap;
}

void Key::setPosition(const glm::vec2& pos)
{
    posIni = pos;
    sprite->setPosition(glm::vec2(float(tileMapDispl.x + posIni.x), float(tileMapDispl.y + posIni.y)));
}

bool Key::checkState()
{
    return got;
}