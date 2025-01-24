#pragma once
#include <wx/wx.h>
class GameLogic
{
public:
	GameLogic(){};
	void play_turn(wxCommandEvent& event, char Player, char grid[3][3], int position);

	bool full_grid(char grid[3][3]);

	int check_winner(char grid[3][3]);

	char game_grid[3][3] = { {'\0','\0','\0',},{'\0','\0','\0'},{'\0','\0','\0'} };

	int Counter = 0;

	char Player1 = 'X', Player2 = 'O';

};

