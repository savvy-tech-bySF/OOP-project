#include <vector>
#include "MazeCards.cpp" 

class Board {
public:
    Board(); 
    void initializeBoard(); 
    void insertMazeCard(const MazeCards& card, const Coordinates& coordinates); 
    void movePlayer(); 
    void moveCard(); 

private:
    std::vector<std::vector<MazeCards>> grid; // 2D grid of MazeCards
};