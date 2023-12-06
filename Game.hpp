#pragma once
#include "Player.hpp" 
#include "Board.hpp"
#include "Stack.hpp"
#include "TreasureCards.cpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#ifndef GAME_HPP
#define GAME_HPP
class Game {
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 700;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assets = NULL;
    SDL_Texture* assets1 = NULL;
    SDL_Texture* player_asset = NULL;
    SDL_Texture* cards1 = NULL;
    SDL_Texture* cards2 = NULL;
    SDL_Texture* cards3 = NULL;
    SDL_Texture* treasureTexture = NULL;
    SDL_Texture* ShowTreasure = NULL;


public:
    Game(); 
    void startGame(); 
    void initializePlayers();
    void playTurn(); 
    bool isGameOver(); 
    void displayWinner(); 
    bool init();
    bool loadMedia();
    bool handleKeyboardEvent(SDL_Event& e);
    void highlightElements(bool highlightActiveRight, bool highlightActiveLeft);
    void Initialize();
    void close();
    SDL_Texture* loadTexture( std::string path );
    

private:
    Player* players[4]; // Assuming all 4 players are playing
    Player* current; 
    Player* red;
    Player* yellow;
    Player* green;
    Player* blue;
    Board board;
    bool highlightActiveRight = false;
    bool highlightActiveLeft = false;
    bool rotate = false;
    bool showCard = false;
    int tick;
    int arrow_num{0};
    //Stack treasureDeck;
    std::vector <SDL_Rect> arrow = {{672, 158, 45, 45},{672, 158, 45, 45},{672, 158, 45, 45},
										{518, 656, 45, 45},{518, 656, 45, 45},{518, 656, 45, 45},
										{0, 507, 45, 45},{0, 507, 45, 45},{0, 507, 45, 45},
										{162, 3, 45, 45},{162, 3, 45, 45},{162, 3, 45, 45}};
    std::vector <SDL_Rect> arrow_dest = {{672, 158, 45, 45},{672, 337, 45, 45}, {672, 510, 45, 45}, {518, 656, 45, 45},
                                        {345, 656, 45, 45}, {162, 653, 45, 45}, {0, 507, 45, 45}, {0, 328, 45, 45},
                                        {0, 155, 45, 45}, {162, 3, 45, 45}, {345, 4, 45, 45}, {518, 5, 45, 45} };
};

#endif