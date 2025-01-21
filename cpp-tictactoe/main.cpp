#include <iostream>

void display_grid(char grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << grid[i][j] << "\t";
        }
        std::cout << std::endl << std::endl;
    }
}

int check_winner(char grid[3][3]) // Renvoie 0 si pas de vainqueur, 1 si X gagne et 2 si O gagne
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

void play_turn(char Player, char grid[3][3])
{
    while (true)
    {
        int column, row;
        std::cout << "Entrez la colonne puis la rangee (1-3) : ";
        std::cin >> column >> row;

        if ((int)column < 1 || (int)column > 3 || (int)row < 1 || (int)row > 3)
        {
            std::cout << "Erreur: Veuillez entrer un nombre valide entre 1 et 3" << std::endl;
        }
        else if (grid[(int)row - 1][(int)column - 1] != '\0')
        {
            std::cout << "Erreur: Cette case est dejà occupee. Choisissez-en une autre." << std::endl;
        }
        else
        {
            grid[(int)row - 1][(int)column - 1] = Player;
            break;
        }
    }
}

int main()
{
    char grid[3][3] = { {'\0','\0','\0'}, {'\0','\0','\0'}, {'\0','\0','\0'} };
    int n_coup = 0;

    while (check_winner(grid) == 0 && n_coup < 9)
    {
        display_grid(grid);
        char Player = (n_coup % 2 == 0) ? 'X' : 'O';
        play_turn(Player, grid);
        n_coup++;
    }

    display_grid(grid);

    int winner = check_winner(grid);
    if (winner == 1)
    {
        std::cout << "Le joueur X a gagne !" << std::endl;
    }
    else if (winner == 2)
    {
        std::cout << "Le joueur O a gagne !" << std::endl;
    }
    else
    {
        std::cout << "Match nul !" << std::endl;
    }

    return 0;
}
