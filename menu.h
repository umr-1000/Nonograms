#include <ncurses.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#ifndef _MENU_H_
#define _MENU_H_


class Menu
{
    public:
        Menu(WINDOW * win);

        struct Settings;
        Settings readSettings();
        void saveSettings(Settings& settings);
        void resetSettings();

        void levelComplete(int mode, int level);

        void draw(int& mode);
        int handleMovement(int& mode, int& level);
        void clearMenu();
        void nonoMenu();
        void levelMenu(int & mode);
        void settingsMenu(Settings& settings);

    private:
        WINDOW * cursorWin;
        int selectedMenu;
        int selectedItem;
};

Menu::Menu(WINDOW * win)
{
    cursorWin = win;
    selectedMenu = 0;
    selectedItem = 0;
    keypad(cursorWin, true);
}


struct Menu::Settings
{
    int fillControl;
    int unfillControl;
    vector<int> save5;
    vector<int> save10;
	vector<int> save15;
};

Menu::Settings Menu::readSettings()
{
    string filename = "settings.txt";
    Settings settings;
    ifstream file(filename);

    if (file.is_open()) {
        file >> settings.fillControl;
        file >> settings.unfillControl;

        int value;
        for (int i = 0; i < 15 && file >> value; ++i) {
            settings.save5.push_back(value);
        }
        for (int i = 0; i < 15 && file >> value; ++i) {
            settings.save10.push_back(value);
        }
        for (int i = 0; i < 15 && file >> value; ++i) {
            settings.save15.push_back(value);
        }

        file.close();
    } else {
        settings.fillControl = 'z';
		settings.unfillControl = 'x';
		for (int i = 0; i < 15; ++i) {
            settings.save5.push_back(0);
        }
        for (int i = 0; i < 15; ++i) {
            settings.save10.push_back(0);
        }
        for (int i = 0; i < 15; ++i) {
            settings.save15.push_back(0);
        }
    }
    return settings;
}

void Menu::saveSettings(Settings& settings)
{
    string filename = "settings.txt";
    ofstream file(filename);

    if (file.is_open()) {
        file << settings.fillControl << " " << settings.unfillControl << "\n";

        for (int i = 0; i < 15; ++i) {
            file << settings.save5[i] << " ";
        }
        file << "\n";

        for (int i = 0; i < 15; ++i) {
            file << settings.save10[i] << " ";
        }
        file << "\n";

        for (int i = 0; i < 15; ++i) {
            file << settings.save15[i] << " ";
        }
        file << "\n";
        
        file.close();
    }
}

void Menu::resetSettings()
{
    string filename = "settings.txt";
    ofstream file(filename);
    if (file.is_open()) {
        file << "122 120\n";
        for (int i = 0; i < 15; ++i) {
            file << "0 ";
        }
        file << "\n";
        for (int i = 0; i < 15; ++i) {
            file << "0 ";
        }
        file << "\n";
        for (int i = 0; i < 15; ++i) {
            file << "0 ";
        }
        file << "\n";
        
        file.close();
    }



}

void Menu::levelComplete(int mode, int level)
{
    Settings settings = readSettings();

    switch (mode)
    {
    case 5:
        settings.save5[level - 1] = 1;
        break;
    case 10:
        settings.save10[level - 1] = 1;
        break;
    case 15:
        settings.save15[level - 1] = 1;
        break;
    default:
        break;
    }
    saveSettings(settings);
}

void Menu::draw(int& mode)
{
    int position = 2;
    string menus[3] = {"Nonograms", "Levels", "Settings"};
    for (int i = 0; i < 3; i++)
    {
        mvwaddch(cursorWin, 0, position, ' ');
            position++;
        if (selectedMenu == i)
        {
            wattron(cursorWin, COLOR_PAIR(4));
            mvwprintw(cursorWin, 0, position, menus[i].c_str());
            wattroff(cursorWin, COLOR_PAIR(4));
        }
        else
            mvwprintw(cursorWin, 0, position, menus[i].c_str());
        position += menus[i].length();
        mvwaddch(cursorWin, 0, position, ' ');
        position += 2;
    }

    Settings settings = readSettings();

    switch (selectedMenu)
    {
    case 0:
        nonoMenu();
        break;
    case 1:
        levelMenu(mode);
        break;
    case 2:
        settingsMenu(settings);
        break;
    default:
        break;
    }
    wrefresh(cursorWin);
}

int Menu::handleMovement(int& mode, int& level)
{
    int choice = wgetch(cursorWin);
    Settings settings = readSettings();

    switch (choice)
    {
    case KEY_LEFT:
    case 'a':
        if (selectedMenu != 0)
        {
            selectedMenu--;
            selectedItem = 0;
        }
        break;
    case KEY_RIGHT:
    case 'd':
        if (selectedMenu != 2)
        {
            selectedMenu++;
            selectedItem = 0;
        }
    case KEY_UP:
    case 'w':
        if (selectedMenu == 2 && (selectedItem == 3 || selectedItem == 4))
            selectedItem -= 2;
        else if (selectedItem != 0)
            selectedItem--;
        break;
    case KEY_DOWN:
    case 's':
        if (selectedMenu == 1)
        {
            if (selectedItem != 10)
                selectedItem++;
        }
        if (selectedMenu == 2)
        {
            if (selectedItem != 4)
                selectedItem++;
        }
        break;
    default:
        break;
    }
    if (choice == 10 || choice == 32 || choice == settings.fillControl || choice == settings.unfillControl)
    {
        if (selectedMenu == 1)
        {
            if (selectedItem == 0)
            {
                mode += 5;
                if (mode > 15)
                    mode = 5;
            }
            else
            {
                level = selectedItem;
                choice = 200;
            }
        }
        if (selectedMenu == 2)
        {
            if (selectedItem == 0)
            {
                settings.fillControl = '_';
                settingsMenu(settings);
                wrefresh(cursorWin);
                settings.fillControl = getch();
                saveSettings(settings);
            }
            if (selectedItem == 1)
            {
                settings.unfillControl = '_';
                settingsMenu(settings);
                wrefresh(cursorWin);
                settings.unfillControl = getch();
                saveSettings(settings);
            }
            if (selectedItem == 2 || selectedItem == 3)
            {
                saveSettings(settings);
                mode = 0;
                choice = 200;
            }
            if (selectedItem == 4)
            {
                resetSettings();
            }
        }
    }
    return choice;
}

void Menu::clearMenu()
{
    for (int i = 1; i < 25; i++)
        for (int j = 1; j < 48; j++)
            mvwaddch(cursorWin, i, j, ' ');
}

void Menu::nonoMenu()
{
    clearMenu();

    Settings settings = readSettings();

    mvwprintw(cursorWin, 2, 2, "Welcome to Nonograms! This is a logic puzzle");
    mvwprintw(cursorWin, 3, 2, "in which cells in a grid must be colored or");
    mvwprintw(cursorWin, 4, 2, "left blank according to numbers at the side");
    mvwprintw(cursorWin, 5, 2, "of the grid revealing a pixel-art image.");
    mvwprintw(cursorWin, 7, 19, "How to play:");
    mvwprintw(cursorWin, 9, 2, "Each row and column have listed lengths of");
    mvwprintw(cursorWin, 10, 2, "unbroken lines of filled squares. For");
    mvwprintw(cursorWin, 11, 2, "example, a row with 3 1 means that there is a");
    mvwprintw(cursorWin, 12, 2, "row of 3 blocks together and then 1 block");
    mvwprintw(cursorWin, 13, 2, "after in the rest of the row, which is");
    mvwprintw(cursorWin, 14, 2, "separated by 1 or more empty blocks. By");
    mvwprintw(cursorWin, 15, 2, "filling in each row and column, you are able");
    mvwprintw(cursorWin, 16, 2, "to unveil a pixel-art image.");
    mvwprintw(cursorWin, 18, 20, "Controls:");
    mvwprintw(cursorWin, 20, 23, "Select Filled Block:");
    mvwprintw(cursorWin, 21, 5, "Movement:             ");
    mvwaddch(cursorWin, 21, 28, settings.fillControl);
    mvwprintw(cursorWin, 21, 29, " OR [ENTER]");
    mvwprintw(cursorWin, 22, 4, "↑   OR   w");
    mvwprintw(cursorWin, 23, 3, "←↓→      ASD       Select Un-filled Block:");
    mvwaddch(cursorWin, 24, 27, settings.unfillControl);
    mvwprintw(cursorWin, 24, 28, " OR [SPACE]");
}

void Menu::levelMenu(int& mode)
{
    clearMenu();

    Settings settings = readSettings();

    if (selectedItem == 0)
        wattron(cursorWin, COLOR_PAIR(6));
    mvwprintw(cursorWin, 2, 2, "Mode:                                        ");
    switch (mode)
    {
    case 5:
        mvwaddch(cursorWin, 2, 8, 53);
        mvwaddch(cursorWin, 2, 9, 'x');
        mvwaddch(cursorWin, 2, 10, 53);
        break;
    case 10:
        mvwaddch(cursorWin, 2, 8, 49);
        mvwaddch(cursorWin, 2, 9, 48);
        mvwaddch(cursorWin, 2, 10, 'x');
        mvwaddch(cursorWin, 2, 11, 49);
        mvwaddch(cursorWin, 2, 12, 48);
        break;
    case 15:
        mvwaddch(cursorWin, 2, 8, 49);
        mvwaddch(cursorWin, 2, 9, 53);
        mvwaddch(cursorWin, 2, 10, 'x');
        mvwaddch(cursorWin, 2, 11, 49);
        mvwaddch(cursorWin, 2, 12, 53);
        break;
     default:
        mode = 5;
        mvwaddch(cursorWin, 2, 8, 53);
        mvwaddch(cursorWin, 2, 9, 'x');
        mvwaddch(cursorWin, 2, 10, 53);
        break;
    }
    wattroff(cursorWin, COLOR_PAIR(6));

    for (int i = 4; i < 14; i++)
        mvwprintw(cursorWin, i, 1, " ");
    

    wattron(cursorWin, COLOR_PAIR(8));
    if (mode == 5)
    {
        for (int i = 4; i < 14; i++)
        {
            if (settings.save5[i - 4] == 1)
                mvwprintw(cursorWin, i, 1, " ");
        }
    }
    else if (mode == 10)
    {
        for (int i = 4; i < 14; i++)
        {
            if (settings.save10[i - 4] == 1)
                mvwprintw(cursorWin, i, 1, " ");
        }
    }
    if (mode == 15)
    {
        for (int i = 4; i < 14; i++)
        {
            if (settings.save15[i - 4] == 1)
                mvwprintw(cursorWin, i, 1, " ");
        }
    }
    wattroff(cursorWin, COLOR_PAIR(8));

    for (int i = 4; i < 14; i++)
    {
        if (selectedItem == i - 3)
        {
            wattron(cursorWin, COLOR_PAIR(6));
            mvwprintw(cursorWin, i, 2, "Level                                        ");
            if (i > 12)
            {
                mvwaddch(cursorWin, i, 8, 49);
                mvwaddch(cursorWin, i, 9, i + 35);
            }
            else
                mvwaddch(cursorWin, i, 8, i + 45);
            wattroff(cursorWin, COLOR_PAIR(6));
        }
        else
        {
            mvwprintw(cursorWin, i, 2, "Level                                        ");
            if (i > 12)
            {
                mvwaddch(cursorWin, i, 8, 49);
                mvwaddch(cursorWin, i, 9, i + 35);
            }
            else
                mvwaddch(cursorWin, i, 8, i + 45);
        }
    }
}

void Menu::settingsMenu(Settings& settings)
{
    clearMenu();

    mvwprintw(cursorWin, 2, 2, "Controls:");

    if (selectedItem == 0)
        wattron(cursorWin, COLOR_PAIR(6));
    mvwprintw(cursorWin, 3, 2, "Select Filled Block:     ");
    mvwaddch(cursorWin, 3, 27, settings.fillControl);
    mvwprintw(cursorWin, 3, 28, "                   ");
    wattroff(cursorWin, COLOR_PAIR(6));

    if (selectedItem == 1)
        wattron(cursorWin, COLOR_PAIR(6));
    mvwprintw(cursorWin, 4, 2, "Select Un-filled Block:  ");
    mvwaddch(cursorWin, 4, 27, settings.unfillControl);
    mvwprintw(cursorWin, 4, 28, "                   ");
    wattroff(cursorWin, COLOR_PAIR(6));

    if (selectedItem == 2 || selectedItem == 3)
        wattron(cursorWin, COLOR_PAIR(6));
    mvwprintw(cursorWin, 6, 2, "Save and Exit Game                           ");
    wattroff(cursorWin, COLOR_PAIR(6));

    if (selectedItem == 4)
        wattron(cursorWin, COLOR_PAIR(6));
    mvwprintw(cursorWin, 8, 2, "Reset Game                                   ");
    wattroff(cursorWin, COLOR_PAIR(6));    
}

#endif