#ifndef SCENE_H
#define SCENE_H

#include "raymob.h"
#include "sprite.h"
#include <vector>

class Scene : public Sprite
{
public:
	/// @brief Constructor
	Scene();
	/// @brief Destructor
	virtual ~Scene();

	void AddObject(Sprite* object);
	void DeleteObject(Sprite* object);
	void RemoveObject(Sprite* object);

	int activescene;
	enum State {running, closegame};
	State state = running;

	friend class Core;
private:
	virtual void UpdateObject(float deltatime);
	std::vector<Sprite*> sprites;
protected:
	void CloseGame();
};

#endif
