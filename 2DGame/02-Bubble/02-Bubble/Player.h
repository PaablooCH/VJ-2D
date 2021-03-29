#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE


#include "Sprite.h"
#include "TileMap.h"
#include "Extended_GLUT_KEYS.h"
#include "PlayerStats.h"


// Player is basically a Sprite that represents the player. As such it has
// all properties it needs to track its movement, jumping, and collisions.


class Player
{

public:
	void init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram);
	void update(int deltaTime);
	void render();
	
	void setTileMap(TileMap *tileMap);
	void setPlayerStats(PlayerStats *pStats);
	void setPosition(const glm::vec2 &pos);

	void actuStatsPos(const glm::vec2& pos);

	void teleport(const glm::vec2& pos);


	glm::vec2 getPosPlayer() const { return sprite->getPosition(); }
	
private:
	bool bJumping;
	glm::ivec2 tileMapDispl, posPlayer, posAnt;
	int jumpAngle, startY;
	Texture spritesheet;
	Sprite *sprite;
	TileMap *map;
	PlayerStats *playerStats;
	int cont;
	bool isRight;
	bool isAnimation;
	bool isClimbing;
	bool isDamaged;
	int health, exp;
	bool *powerUp;
};


#endif // _PLAYER_INCLUDE