#include <fstream>
#include <sstream>

#include "game.h"

Game::Game()
{
//    InitAudioDevice();

    Vector2 a;
    a.x = SCRWIDTH / 2;
    a.y = SCRHEIGHT / 2;
    button = new Button("make sound!",a);
    AddObject(button);
    button->SetMethod(std::bind(&Game::PlayMusic, this));
    button->scale = 2.5f;
    PlayMusicStream(track);

    text = new TextSprite();
    AddObject(text);
    Vector2 pos = Vector2();
    pos.x = SCRWIDTH / 2;
    pos.y = SCRHEIGHT / 4;
    text->position = pos;
}

Game::~Game()
{
    
}

void Game::update(float deltaTime)
{
    if (playing)
    {
        UpdateMusicStream(track);
        return;
    }

    if (timer >= 10.0f)
    {
        PlayMusic();
    }
    timer += deltaTime;
}

void Game::PlayMusic()
{
    if (playing) { return; }
    track = ResourceManager::Instance()->GetMusic("sometimes.mp3");
    PlayMusicStream(track);
    text->SetMessage(std::to_string(GetMusicTimeLength(track)));
    playing = true;
}