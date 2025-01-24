#include "GameLogic.h"


int GameLogic::check_winner(char grid[3][3]) // Renvoie 0 si pas de vainqueur, 1 si X gagne et 2 si O gagne
{
    // Check diagonals
    if ((grid[0][0] != '\0' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) ||
        (grid[0][2] != '\0' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]))
    {
        return (grid[1][1] == 'X') ? 1 : 2;
    }
    // Check horizontals
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] != '\0' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
        {
            return (grid[i][0] == 'X') ? 1 : 2;
        }
    }
    // Check verticals
    for (int i = 0; i < 3; i++)
    {
        if (grid[0][i] != '\0' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
        {
            return (grid[0][i] == 'X') ? 1 : 2;
        }
    }
    return 0;
}


void GameLogic::play_turn(wxCommandEvent& event, char Player, char grid[3][3], int position)
{
    if (position < 0 || position >= 9) return;

    int row = position / 3;
    int column = position % 3;

    if (grid[row][column] == '\0')
    {
        grid[row][column] = Player;
        Counter++;  // increment the turn counter
    }
}

bool GameLogic::full_grid(char grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == '\0')
            {
                return false;
            }
        }
    }
    return true;
}
