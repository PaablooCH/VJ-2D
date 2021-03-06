#ifndef _TILE_MAP_INCLUDE
#define _TILE_MAP_INCLUDE


#include <glm/glm.hpp>
#include "Texture.h"
#include "ShaderProgram.h"




class TileMap
{

public:
	
	static TileMap *createTileMap(const string &levelFile, const glm::vec2 &minCoords, ShaderProgram &program);

	TileMap(const string &levelFile, const glm::vec2 &minCoords, ShaderProgram &program);
	~TileMap();

	void render() const;
	void free();
	
	int getTileSize() const { return tileSize; }

	bool collisionMoveLeft(const glm::ivec2 &pos, const glm::ivec2 &size) const;
	bool collisionMoveRight(const glm::ivec2 &pos, const glm::ivec2 &size) const;
	bool collisionMoveStairsLeft(const glm::ivec2& pos, const glm::ivec2& size) const;
	bool collisionMoveStairsRight(const glm::ivec2& pos, const glm::ivec2& size) const;
	bool collisionMoveDown(const glm::ivec2 &pos, const glm::ivec2 &size, int *posY) const;
	bool roofMoveDown(const glm::ivec2& pos, const glm::ivec2& size, int* posY) const;
	bool collisionMoveUp(const glm::ivec2& pos, const glm::ivec2& size) const;
	bool collisionFall(const glm::ivec2& pos, const glm::ivec2& size, int* posY) const;
	bool isStairs(const glm::ivec2& pos, const glm::ivec2& size) const;
	bool checkPlayerLeft(const glm::ivec2& pos, const glm::ivec2& size) const;
	bool checkPlayerRight(const glm::ivec2& pos, const glm::ivec2& size) const;
	bool checkDamage(const glm::ivec2& pos, const glm::ivec2& size, bool helmet) const;
	bool checkPlayerDown(const glm::ivec2& pos, const glm::ivec2& size) const;
	bool checkIfPlayer(const glm::ivec2& pos, const glm::ivec2& size) const;
	bool checkIfKey(const glm::ivec2& pos, const glm::ivec2& size) const;
	bool checkIfChip(const glm::ivec2& pos, const glm::ivec2& size) const;
	void clearPosition(int id) const;
	void updatePositionTile(const glm::ivec2& posAc, const glm::ivec2& posAnt,const glm::ivec2& size, int id) const;
	void updatePositionFakeRoof(const glm::ivec2& posAc, const glm::ivec2& posAnt, const glm::ivec2& size, int id) const;
	void openDoor(const glm::ivec2& pos) const;
	bool checkEnemyBulletDamage(const glm::ivec2& pos, const glm::ivec2& size) const;

	
private:
	bool loadLevel(const string &levelFile);
	void prepareArrays(const glm::vec2 &minCoords, ShaderProgram &program);

private:
	GLuint vao;
	GLuint vbo;
	GLint posLocation, texCoordLocation;
	glm::ivec2 position, mapSize, tilesheetSize;
	int tileSize, blockSize;
	Texture tilesheet;
	glm::vec2 tileTexSize;
	int *map;
	int *characMap;

};


#endif // _TILE_MAP_INCLUDE