#ifndef GAME_H
#define GAME_H

#include "framework/scene.h"
#include "settings.h"
#include "framework/drawsprite.h"
#include "framework/textsprite.h"
#include "framework/button.h"

class Game : public Scene
{
protected:

public:
    //constructor
    Game();

    //destructor
    ~Game();

private:

    void update(float deltaTime);

    void PlayMusic();

    TextSprite* text;

    Music track;

    Button* button;

    bool playing = false;

    float timer = 0;
};

#endif
