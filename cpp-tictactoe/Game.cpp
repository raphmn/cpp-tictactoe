#include "Game.h"
#include "GameLogic.h"

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
wxEND_EVENT_TABLE()

Frame::Frame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 400))
{
    game_logic = new GameLogic();

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxGridSizer* grid = new wxGridSizer(3, 3, 0, 0);
    wxBoxSizer* quit = new wxBoxSizer(wxVERTICAL);

    for (int i = 0; i < 9; i++)
    {
        btn[i] = new wxButton(this, 1000 + i, "");
        btn[i]->Bind(wxEVT_BUTTON, &Frame::OnButtonClicked, this); 
        grid->Add(btn[i], 0, wxEXPAND | wxALL);
    }

    wxButton* quit_button = new wxButton(this, wxID_ANY, "Quitter");
    quit_button->Bind(wxEVT_BUTTON, &Frame::close_game, this);
    quit->Add(quit_button, 0, wxALIGN_RIGHT);

    sizer->Add(grid, 7, wxEXPAND | wxALL, 5);
    sizer->Add(quit, 1, wxEXPAND | wxALL, 5);

    this->SetSizerAndFit(sizer);
}

void Frame::OnButtonClicked(wxCommandEvent& event)
{
    int id = event.GetId() - 1000;
    int row = id / 3;
    int col = id % 3;

    if (game_logic->game_grid[row][col] == '\0')
    {
        char player = (game_logic->Counter % 2 == 0) ? game_logic->Player1 : game_logic->Player2;

        game_logic->play_turn(event, player, game_logic->game_grid, id);

        btn[id]->SetLabel(wxString::Format("%c", player));

        int winner = game_logic->check_winner(game_logic->game_grid);
        if (winner != 0)
        {
            wxString message = (winner == 1) ? "Player X wins!" : "Player O wins!";
            wxMessageBox(message, "Game Over", wxOK | wxICON_INFORMATION, this);
            this->Close(true);
        }
        else if (game_logic->full_grid(game_logic->game_grid))
        {
            wxMessageBox("Tie !", "Game Over", wxOK | wxICON_INFORMATION, this);
            this->Close(true);
        }
    }
}


void Frame::close_game(wxCommandEvent& event)
{
    this->Close(true);
}

Frame::~Frame()
{
    delete game_logic; // Ensure the allocated memory is released
}


bool Game::OnInit()
{
    Frame* game_frame = new Frame("Tic Tac Toe");
    game_frame->Show();
    return true;
}

wxIMPLEMENT_APP(Game);