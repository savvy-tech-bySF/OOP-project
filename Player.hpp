#pragma once
#include "Stack.hpp" 
#include "Coordinates.hpp"
#include "TreasureCards.cpp" 
#include "MazeCards.hpp" 
#include <vector>
#include <SDL.h>
#ifndef PLAYER_HPP
#define PLAYER_HPP
//Todo: define and then #include <SDL.h> 

class Player {

public:
    Player();
    Player(int ID, int startX, int startY);

    void setID(int ID);
    int getID() const;
    void addCard(Treasure t);
    Treasure getTop();
    void pop();
    void DrawPlayer(SDL_Renderer* gRenderer, SDL_Texture* asset);
    //void move(SDL_KeyboardEvent event); //Todo: Handle player movement based on SDL keyboard event (to be defined) 

    //bool checkTreasure(); // Check if the player found any treasure

    //TreasureCards* getFound(); // Return array of found treasure cards
    // void addTreasureCard(TreasureCards* Card);
    bool validate_move(SDL_Rect* adjacentCard, char direction, std::vector<std::vector<Cards*>> *grid, std::vector<SDL_Rect> allmazecards, bool current = false);
    void place_maze_card(); // Place the out of range maze card on the board
    void move_player(char direction, std::vector<std::vector<Cards*>> *grid, std::vector<SDL_Rect> allmazecards);
//private:
    int playerID;
    //int treasures; if we change the amount of players who can play. Default are 4
    //Stack cards;
    int row; 
    int col;
    SDL_Rect src;
    SDL_Rect move; 
    std::vector<Treasure> toFind; /*
    //! Assuming there are four players playing so each player gets 6 treasure cards */ 
    MazeCards mazecard;
};

#endif