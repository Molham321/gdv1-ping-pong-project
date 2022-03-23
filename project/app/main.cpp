
#include "game.h"
#include "application.h"


void main()
{
	run();
	CApplication Application;
	RunApplication(1080, 720, "Ping-Pong", &Application);
}