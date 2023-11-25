#pragma once
#include "Game.hpp"

int main(int argc, char* argv[])
{
    Game game;
    srand(time(NULL));
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
		//Load media
    if( !game.loadMedia() ){
        printf( "Failed to load media!\n" );
        return 0;
    }

    game.startGame();
    game.close();
    return 0;
}