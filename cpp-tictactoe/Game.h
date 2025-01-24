#pragma once
#include <wx/wx.h>
#include "GameLogic.h"


class Frame : public wxFrame
{
public:
    Frame(const wxString& title);
    ~Frame();
    void close_game(wxCommandEvent& event);
    void OnButtonClicked(wxCommandEvent& event);
private:
    wxDECLARE_EVENT_TABLE();
    GameLogic* game_logic;
    wxButton* btn[9];
};


class Game : public wxApp
{
public:
	bool OnInit() override;
};

