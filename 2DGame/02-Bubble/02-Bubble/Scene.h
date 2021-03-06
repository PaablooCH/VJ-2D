#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include "TileMap.h"
#include "Teleport.h"
#include "PlayerStats.h"
#include "Key.h"
#include "RescueGirl.h"

#define CAMERA_WIDTH 640
#define CAMERA_HEIGHT 640



class Scene
{

public:
	Scene();
	~Scene();

	virtual void init(Player* player, int selectPortal) = 0;
	virtual void update(int deltaTime) = 0;
	virtual void render() = 0;

	void updateCamera();
	void deleteKey1();
	void deleteGirl1();

protected:
	void initShaders();

protected:
	TileMap *map;
	Player *player;
	Teleport* teleport1;
	PlayerStats *playerStats;
	RescueGirl *girl1;
	Key *key1;
	ShaderProgram texProgram;
	float currentTime;
	glm::mat4 projection;
	int init_x_tiles, init_y_tiles;

	glm::vec2 posCamera;
};


#endif // _SCENE_INCLUDE

