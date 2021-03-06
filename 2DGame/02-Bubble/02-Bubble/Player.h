#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE


#include "Sprite.h"
#include "TileMap.h"
#include "Extended_GLUT_KEYS.h"
#include "PlayerStats.h"
#include "Bullet.h"




class Player
{

public:

	Player();
	~Player();

	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, int lvl);
	void update(int deltaTime);
	void render();

	void setTileMap(TileMap* tileMap);
	void setPlayerStats(PlayerStats* pStats);
	void setPosition(const glm::vec2& pos);

	void teleport(int lvl);

	bool checkHit();
	bool checkRight();
	bool isAnAnimation();
	bool getDead();
	bool isAGirl(int lvl);
	bool isAKey(int lvl);
	bool isPowerUp(int lvl);
	bool isAWin();
	void bonusBoots();
	void bonusBattery();
	void bonusHelmet();
	void bonusBook();
	void bonusArmor();
	void bonusShoot();
	int getLvl();

	void winExp();
	void winKey();
	void loseKey();
	void winBonus();
	void winBullets();
	void winGirl();
	void changeLvl(int newLvl);
	void becomeGod();


	glm::vec2 getPosPlayer() const { return sprite->getPosition(); }

private:
	bool bJumping;
	bool god;
	glm::ivec2 tileMapDispl, posPlayer, posAnt;
	int jumpAngle, startY;
	Texture spritesheet;
	Sprite* sprite;
	Sprite* spriteDead;
	TileMap* map;
	PlayerStats* playerStats;
	Bullet* bulletLeft, * bulletRight;
	int cont;
	bool isRight;
	bool isAnimation;
	bool isClimbing;
	bool isHitting;
	bool isDamaged;
	bool isDead;
	bool hasHelmet;
	int lvl, speed, jump_height, life_damage, exp_obtained, bullets_cont;

	int health, exp, nkeys;
	bool* powerUp;
	bool* girlRescued;
	bool* keys;
};


#endif // _PLAYER_INCLUDE