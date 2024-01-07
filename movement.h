#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_
#include <ncurses.h>

class Movement
{
    public:
        Movement(WINDOW * win, int mode, int array[15][15]);

        void mvup(int array[15][15]);
        void mvdown(int array[15][15]);
        void mvleft(int array[15][15]);
        void mvright(int array[15][15]);
        void correct(int array[15][15], int i);
        void incorrect(int array[15][15]);
        void printFilled(int array[15][15]);
        int checkComplete(int mode);
        void select(int array[15][15], int choice);
        int getmv(int array[15][15], int mode, int level);
        void display();
    
    private:
        int yLoc, xLoc, yMax, xMax, cp, lives, hints;
        int found[15][15];
        WINDOW * cursorWin;
};

Movement::Movement(WINDOW * win, int mode, int array[15][15])
{
    cursorWin = win;
    yLoc = 10;
    xLoc = 18;
    keypad(cursorWin, true);

    lives = 3;
    hints = 3;

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            found[i][j] = 0;

    switch (mode)
    {
    case 5:
        yMax = 13;
        xMax = 24;
        cp = 3;
        break;
    case 10:
        yMax = 18;
        xMax = 34;
        cp = 4;
        break;
    case 15:
        yMax = 23;
        xMax = 44;
        cp = 3;
    default:
        break;
    }
}

void Movement::mvup(int array[15][15])
{
    printFilled(array);
    int colourPair;

    if (yLoc < 11)
        yLoc = 11;
    else if (cp == 3)
	    cp = 4;
	else
		cp = 3;
    
    if (found[yLoc - 10][(xLoc - 18)/2] == 1)
    {
        if (array[yLoc - 10][(xLoc - 18)/2] == 0)
            colourPair = 1;
        else
            colourPair = 6;
    }
    else
        colourPair = cp;

	wattrset(cursorWin, COLOR_PAIR(colourPair));
    mvwaddch(cursorWin, yLoc, xLoc, ' ');
    mvwaddch(cursorWin, yLoc, xLoc + 1, ' ');
    wattroff(cursorWin, COLOR_PAIR(colourPair));
    yLoc--;
}

void Movement::mvdown(int array[15][15])
{
    printFilled(array);
    int colourPair;

    if (yLoc > yMax)
        yLoc = yMax;
    else if (cp == 3)
	    cp = 4;
	else
		cp = 3;
    
    if (found[yLoc - 10][(xLoc - 18)/2] == 1)
    {
        if (array[yLoc - 10][(xLoc - 18)/2] == 0)
            colourPair = 1;
        else
            colourPair = 6;
    }
    else
        colourPair = cp;

	wattrset(cursorWin, COLOR_PAIR(colourPair));
    mvwaddch(cursorWin, yLoc, xLoc, ' ');
    mvwaddch(cursorWin, yLoc, xLoc + 1, ' ');
    wattroff(cursorWin, COLOR_PAIR(colourPair));
    yLoc++;
}

void Movement::mvleft(int array[15][15])
{
    printFilled(array);
    int colourPair;

    if (xLoc < 20)
        xLoc = 20;
    else if (cp == 3)
	    cp = 4;
	else
		cp = 3;

    colourPair = cp;
    if (found[yLoc - 10][(xLoc - 18)/2] == 1)
    {
        if (array[yLoc - 10][(xLoc - 18)/2] == 0)
            colourPair = 1;
        else
            colourPair = 6;
    }

    wattrset(cursorWin, COLOR_PAIR(colourPair));
    mvwaddch(cursorWin, yLoc, xLoc, ' ');
    mvwaddch(cursorWin, yLoc, xLoc + 1, ' ');
    wattroff(cursorWin, COLOR_PAIR(colourPair));

    xLoc = xLoc - 2;
}

void Movement::mvright(int array[15][15])
{
    printFilled(array);
    int colourPair;

    if (xLoc > xMax)
        xLoc = xMax;
    else if (cp == 3)
	    cp = 4;
	else
		cp = 3;

    colourPair = cp;
    if (found[yLoc - 10][(xLoc - 18)/2] == 1)
    {
        if (array[yLoc - 10][(xLoc - 18)/2] == 0)
            colourPair = 1;
        else
            colourPair = 6;
    }
    
    

    wattrset(cursorWin, COLOR_PAIR(colourPair));
    mvwaddch(cursorWin, yLoc, xLoc, ' ');
    mvwaddch(cursorWin, yLoc, xLoc + 1, ' ');
    wattroff(cursorWin, COLOR_PAIR(colourPair));

    xLoc = xLoc + 2;
}

void Movement::correct(int array[15][15], int i)
{
    int colourPair;
    switch (i)
    {
    case 0:
        colourPair = 1;
        break;
    case 1:
        colourPair = 6;
        break;
    }

    wattrset(cursorWin, COLOR_PAIR(colourPair));
    mvwaddch(cursorWin, yLoc, xLoc, ' ');
    mvwaddch(cursorWin, yLoc, xLoc + 1, ' ');
    wattroff(cursorWin, COLOR_PAIR(colourPair));

    mvwaddch(cursorWin, 7, 12, hints + 48);
    wmove(cursorWin, 7, 13);

}

void Movement::incorrect(int array[15][15])
{
    lives--;
    
    wattrset(cursorWin, COLOR_PAIR(7));
    mvwaddch(cursorWin, yLoc, xLoc, ' ');
    mvwaddch(cursorWin, yLoc, xLoc + 1, ' ');
    wattroff(cursorWin, COLOR_PAIR(7));

    mvwaddch(cursorWin, 5, 12, lives + 48);
}

void Movement::select(int array[15][15], int choice)
{
    int y = yLoc - 10;
    int x = (xLoc - 18)/2;

    if (found[y][x] == 1)
        return;
    else if (choice == 2)
    {
        found[y][x] = 1;
        hints--;
        correct(array, array[y][x]);
    }
    else if (array[y][x] == choice)
    {
        found[y][x] = 1;
        correct(array, choice);
    }
    else
    {
        found[y][x] = 1;
        incorrect(array); 
    }
}

void Movement::printFilled(int array[15][15])
{
    for (int i = 0; i <= 15; i++)
    {
        for (int j = 0; j <= 15; j++)
        {
            if (found[i][j] == 1)
            {
                if (array[i][j] == 1)
                {
                    wattrset(cursorWin, COLOR_PAIR(6));
                    mvwaddch(cursorWin, i + 10, 2*j + 18, ' ');
                    mvwaddch(cursorWin, i + 10, 2*j + 19, ' ');
                    wattroff(cursorWin, COLOR_PAIR(6));
                }
                else
                {
                    wattrset(cursorWin, COLOR_PAIR(1));
                    mvwaddch(cursorWin, i + 10, 2*j + 18, ' ');
                    mvwaddch(cursorWin, i + 10, 2*j + 19, ' ');
                    wattroff(cursorWin, COLOR_PAIR(1));
                } 
            } 
        }
    }
    for (int i = 10; i < 25; i++)
        mvwprintw(cursorWin, i, 48, "│");  
}

int Movement::checkComplete(int mode)
{
    for (int i = 0; i < mode; i++)
        for (int j = 0; j < mode; j++)
            if (found[i][j] == 0)
                return 0;
    
    return 1;
}

int Movement::getmv(int array[15][15], int mode, int level)
{
    int choice;
    if (lives == 0)
    {
        choice = 'p';
        delay_output(1000);
        mvwprintw(cursorWin, 9, 2, "┌");
	    mvwprintw(cursorWin, 9, 46, "┐");
	    mvwprintw(cursorWin, 17, 2, "└");
	    mvwprintw(cursorWin, 17, 46, "┘");
        for (int i = 3; i < 46; i++)
        {
            mvwprintw(cursorWin, 9, i, "─");
	        mvwprintw(cursorWin, 17, i, "─");
        }
        for (int i = 10; i < 17; i++)
        {
            mvwprintw(cursorWin, i, 2, "│");
	        mvwprintw(cursorWin, i, 46, "│");
        }

        for (int i = 10; i < 17; i++)
            for (int j = 3; j < 46; j++)
                mvwaddch(cursorWin, i, j, ' ');
        
        mvwprintw(cursorWin, 10, 6, "___                   ___");
        mvwprintw(cursorWin, 11, 5, "/ __|__ _ _ __  ___   / _ \\__ _____ _ _");
        mvwprintw(cursorWin, 12, 4, "| (_ / _` | '  \\/ -_) | (_) \\ V / -_) '_|");
        mvwprintw(cursorWin, 13, 5, "\\___\\__,_|_|_|_\\___|  \\___/ \\_/\\___|_|");
        mvwprintw(cursorWin, 15, 10, "Press any button to continue");
        
        wrefresh(cursorWin);
        getch();
    }
    else if (checkComplete(mode) == 1)
    {
        choice = 200;
        delay_output(1000);
        mvwprintw(cursorWin, 7, 2, "┌");
	    mvwprintw(cursorWin, 7, 46, "┐");
	    mvwprintw(cursorWin, 20, 2, "└");
	    mvwprintw(cursorWin, 20, 46, "┘");
        for (int i = 3; i < 46; i++)
        {
            mvwprintw(cursorWin, 7, i, "─");
	        mvwprintw(cursorWin, 20, i, "─");
        }
        for (int i = 8; i < 20; i++)
        {
            mvwprintw(cursorWin, i, 2, "│");
	        mvwprintw(cursorWin, i, 46, "│");
        }

        for (int i = 8; i < 20; i++)
            for (int j = 3; j < 46; j++)
                mvwaddch(cursorWin, i, j, ' ');
        
        mvwprintw(cursorWin, 8, 15, "_                _");
        mvwprintw(cursorWin, 9, 14, "| |   _____ _____| |");
        mvwprintw(cursorWin, 10, 14, "| |__/ -_) V / -_) |");
        mvwprintw(cursorWin, 11, 14, "|____\\___|\\_/\\___|_|");
        mvwprintw(cursorWin, 12, 9, "___                _     _");
        mvwprintw(cursorWin, 13, 8, "/ __|___ _ __  _ __| |___| |_ ___");
        mvwprintw(cursorWin, 14, 7, "| (__/ _ \\ '  \\| '_ \\ / -_)  _/ -_)");
        mvwprintw(cursorWin, 15, 8, "\\___\\___/_|_|_| .__/_\\___|\\__\\___|");
        mvwprintw(cursorWin, 16, 22, "|_|");
        mvwprintw(cursorWin, 18, 10, "Press any button to continue");

        wrefresh(cursorWin);
        getch();
    }
    else
        choice = wgetch(cursorWin);
    switch(choice)
    {
        case KEY_UP:
        case 'w':
            mvup(array);
            display();
            break;
        case KEY_DOWN:
        case 's':
            mvdown(array);
            display();
            break;
        case KEY_LEFT:
        case 'a':
            mvleft(array);
            display();
            break;
        case KEY_RIGHT:
        case 'd':
            mvright(array);
            display();
            break;
        case 32:
        case 'x':
            select(array, 0);
            break;
        case 10:
        case 'z':
            select(array, 1);
            break;
        case 'c':
        case 'h':
            if (hints > 0)
                select(array, 2);
            break;
        default:
            display();
            break;
    }

    return choice;
}

void Movement::display()
{
    wattrset(cursorWin, COLOR_PAIR(5));
    mvwaddch(cursorWin, yLoc, xLoc, ' ');
    mvwaddch(cursorWin, yLoc, xLoc + 1, ' ');
    wattroff(cursorWin, COLOR_PAIR(5));
}

#endif