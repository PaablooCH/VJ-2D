#ifndef _SHOOTENEMY_INCLUDE
#define _SHOOTENEMY_INCLUDE


#include "Sprite.h"
#include "TileMap.h"
#include "Extended_GLUT_KEYS.h"
#include "ShaderProgram.h"
#include "Bullet.h"
#include "Player.h"

class ShootEnemy
{
public:

    ShootEnemy();
    ~ShootEnemy();

    void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, const glm::ivec2& posInicial);
    void update(int deltaTime);
    void render();

    void setTileMap(TileMap* tileMap);
    void setPosition(const glm::vec2& pos);
    void setPlayer(Player* p);
    bool checkAlive();



private:
    glm::ivec2 tileMapDispl, posEnemy, posAnt;
    Texture spritesheet;
    Sprite* sprite;
    vector<Sprite*> sprites;
    TileMap* map;
    ShaderProgram texProgram;
    bool protect, isAlive;
    int cont;
    Bullet* bullet;
    Player* player;
};

#endif