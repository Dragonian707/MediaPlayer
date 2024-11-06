#include "raymob.h"

#include "framework/resourcemanager.h"
#include "framework/core.h"
#include "settings.h"

#include "game.h"

int main()
{
//	SetConfigFlags(FLAG_FULLSCREEN_MODE);
//	SetConfigFlags(FLAG_WINDOW_UNDECORATED);
	InitWindow(SCRWIDTH, SCRHEIGHT, WINDOWNAME);

	ResourceManager* rs = ResourceManager::Instance();
    Scene* s = new Game();
	Core core;

    while (core.running) //while (core.Run(game)) { ; }
    {
		core.Run(s, BACKGROUND);
    }

	rs->Cleanup();
    
	CloseWindow();
    
	return 0;
}
