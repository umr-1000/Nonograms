/*
░█▀█░█▀█░█▀█░█▀█░█▀▀░█▀▄░█▀█░█▄█░█▀▀
░█░█░█░█░█░█░█░█░█░█░█▀▄░█▀█░█░█░▀▀█
░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀░▀░▀▀▀
By Umar Habib
*/

#include <ncurses.h>
#include <locale.h>
#include <iostream>
#include <fstream>
#include "movement.h"
#include "levels.h"
#include "menu.h"
using namespace std;

void winReset(WINDOW *win)
{
	wclear(win);

	wattrset(win, COLOR_PAIR(2));
	mvwprintw(win, 0, 0, "┌");
	mvwprintw(win, 0, 48, "┐");
	mvwprintw(win, 25, 0, "└");
	mvwprintw(win, 25, 48, "┘");

	for (int i = 1; i < 48; i++)
	{
		mvwprintw(win, 0, i, "─");
		mvwprintw(win, 25, i, "─");
	}

	for (int i = 1; i < 25; i++)
	{
		mvwprintw(win, i, 0, "│");
		mvwprintw(win, i, 48, "│");
	}
	wattroff(win, COLOR_PAIR(2));

	wrefresh(win);
}
void selectLevel(int array[15][15], int mode, int level)
{
	switch (mode)
	{
	case 5:
		switch (level)
		{
		case 1:
			l1_5(array);
			break;
		case 2:
			l2_5(array);
			break;
		case 3:
			l3_5(array);
			break;
		case 4:
			l4_5(array);
			break;
		case 5:
			l5_5(array);
			break;
		case 6:
			l6_5(array);
			break;
		case 7:
			l7_5(array);
			break;
		case 8:
			l8_5(array);
			break;
		case 9:
			l9_5(array);
			break;
		case 10:
			l10_5(array);
			break;
		default:
			break;
		}
		break;
	case 10:
		switch (level)
		{
		case 1:
			l1_10(array);
			break;
		case 2:
			l2_10(array);
			break;
		case 3:
			l3_10(array);
			break;
		case 4:
			l4_10(array);
			break;
		case 5:
			l5_10(array);
			break;
		case 6:
			l6_10(array);
			break;
		case 7:
			l7_10(array);
			break;
		case 8:
			l8_10(array);
			break;
		case 9:
			l9_10(array);
			break;
		case 10:
			l10_10(array);
			break;
		default:
			break;
		}
		break;
	case 15:
		switch (level)
		{
		case 1:
			l1_15(array);
			break;
		case 2:
			l2_15(array);
			break;
		case 3:
			l3_15(array);
			break;
		case 4:
			l4_15(array);
			break;
		case 5:
			l5_15(array);
			break;
		case 6:
			l6_15(array);
			break;
		case 7:
			l7_15(array);
			break;
		case 8:
			l8_15(array);
			break;
		case 9:
			l9_15(array);
			break;
		case 10:
			l10_15(array);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
void start(WINDOW *win)
{
	mvwprintw(win, 7, 6, "░█▀█░█▀█░█▀█░█▀█░█▀▀░█▀▄░█▀█░█▄█░█▀▀");
	mvwprintw(win, 8, 6, "░█░█░█░█░█░█░█░█░█░█░█▀▄░█▀█░█░█░▀▀█");
	mvwprintw(win, 9, 6, "░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀░▀░▀▀▀");
	mvwprintw(win, 11, 11, "Press any button to continue");

	wrefresh(win);
	getch();
	winReset(win);
}
void grid5(WINDOW *win)
{	

	winReset(win);

	/* Initialize Grid */

	mvwprintw(win, 9, 0, "┝");							// left border connection 1
	mvwprintw(win, 15, 0, "├");							// left border connection 2
	mvwprintw(win, 9, 17, "╋");							// middle border connection
	mvwprintw(win, 0, 17, "┰");							// top border connection 1
	mvwprintw(win, 0, 28, "┬");							// top border connection 2

	mvwprintw(win, 9, 28, "┥");							// top right of inner border
	mvwprintw(win, 15, 17, "┸");						// bottom left of inner border
	mvwprintw(win, 15, 28, "┘");						// bottom right of inner border

	for (int i = 1; i < 17; i++)						// horizontal line connection
	{
		mvwprintw(win, 9, i, "━");
		mvwprintw(win, 15, i, "─");
	}

	for (int i = 1; i < 9; i++)							// vertical line connection
	{
		mvwprintw(win, i, 17, "┃");
		mvwprintw(win, i, 28, "│");
	}


	/* Initializing Grid Color */
	int cp = 3;
	for (int i = 18; i < 28; i = i + 2)					// from x = 18 --> 27
	{
		for (int j = 10; j < 15; j++)					// from y = 10 --> 14
		{
			if (cp == 3)								// alternate color pair
			cp = 4;
			else
			cp = 3;

			wattrset(win, COLOR_PAIR(cp));
			mvwprintw(win, j, i, "  ");
			wattroff(win, COLOR_PAIR(cp));
		}
	}

	/* Initializing vertical locations*/
	cp = 2;
	for (int i = 18; i < 28; i = i + 2)					// from x = 18 --> 27
	{
		if (cp == 3)									// alternate color pair every column
			cp = 4;
		else
			cp = 3;
		
		wattrset(win, COLOR_PAIR(cp));
		for (int j = 1; j < 9; j++)						// from y = 1 --> 8
			mvwprintw(win, j, i, "  ");
		wattroff(win, COLOR_PAIR(cp));

		mvwprintw(win, 9, i, "━━");
		mvwprintw(win, 15, i, "──");
	}

	/* Initializing horizontal locations*/
	cp = 2;
	for (int j = 10; j < 15; j++)						// from y = 10 --> 14
	{
		if (cp == 3)									// alternate color pair every row
			cp = 4;
		else
			cp = 3;
		
		wattrset(win, COLOR_PAIR(cp));
		for (int i = 1; i < 17; i = i + 2)				// from x = 1 --> 16
			mvwprintw(win, j, i, "  ");
		wattroff(win, COLOR_PAIR(cp));

		mvwprintw(win, j, 17, "┃");
		mvwprintw(win, j, 28, "│");
	}
	
	mvwprintw(win, 1, 5, "Nonograms");
	mvwprintw(win, 2, 6, "Level");
	mvwprintw(win, 3, 8, "5x5");
	mvwprintw(win, 5, 5, "Lives: 3");
	mvwprintw(win, 7, 5, "Hints: 3");

	wrefresh(win);

}
void grid10(WINDOW *win)
{	

	winReset(win);

	/* Initialize Grid */
	mvwprintw(win, 9, 0, "┝");							// left border connection 1
	mvwprintw(win, 20, 0, "├");							// left border connection 2
	mvwprintw(win, 9, 17, "╋");							// middle border connection
	mvwprintw(win, 0, 17, "┰");							// top border connection 1
	mvwprintw(win, 0, 38, "┬");							// top border connection 2

	mvwprintw(win, 9, 38, "┥");							// top right of inner border
	mvwprintw(win, 20, 17, "┸");						// bottom left of inner border
	mvwprintw(win, 20, 38, "┘");						// bottom right of inner border

	for (int i = 1; i < 17; i++)						// horizontal line connection
	{
		mvwprintw(win, 9, i, "━");
		mvwprintw(win, 20, i, "─");
	}

	for (int i = 1; i < 9; i++)							// vertical line connection
	{
		mvwprintw(win, i, 17, "┃");
		mvwprintw(win, i, 38, "│");
	}


	/* Initializing Grid Color */
	int cp = 3;
	for (int i = 18; i < 37; i = i + 2)					// from x = 18 --> 36
	{
		if (cp == 3)									// extra statement for correct grid as grid is even
		cp = 4;
		else
		cp = 3;

		for (int j = 10; j < 20; j++)					// from y = 10 --> 19
		{
			if (cp == 3)								// alternate color pair
			cp = 4;
			else
			cp = 3;

			wattrset(win, COLOR_PAIR(cp));
			mvwprintw(win, j, i, "  ");
			wattroff(win, COLOR_PAIR(cp));
		}
	}

	/* Initializing vertical locations*/
	cp = 2;
	for (int i = 18; i < 37; i = i + 2)					// from x = 18 --> 36
	{
		if (cp == 3)									// alternate color pair every column
			cp = 4;
		else
			cp = 3;

		wattrset(win, COLOR_PAIR(cp));
		for (int j = 1; j < 10; j++)					// from y = 1 --> 9
		{
			mvwprintw(win, j, i, "  ");
		}
		wattroff(win, COLOR_PAIR(cp));

		mvwprintw(win, 9, i, "━━");
		mvwprintw(win, 20, i, "──");
	}

	/* Initializing horizontal locations*/
	cp = 2;
	for (int j = 10; j < 20; j++)						// from y = 10 --> 19
	{
		if (cp == 3)									// alternate color pair every row
			cp = 4;
		else
			cp = 3;

		wattrset(win, COLOR_PAIR(cp));
		for (int i = 1; i < 17; i = i + 2)				// from x = 1 --> 16
		{
			mvwprintw(win, j, i, "  ");
		}
		wattroff(win, COLOR_PAIR(cp));

		mvwprintw(win, j, 17, "┃");
		mvwprintw(win, j, 38, "│");
	}
	
	mvwprintw(win, 1, 5, "Nonograms");
	mvwprintw(win, 2, 6, "Level");
	mvwprintw(win, 3, 7, "10x10");
	mvwprintw(win, 5, 5, "Lives: 3");
	mvwprintw(win, 7, 5, "Hints: 3");

	wrefresh(win);

}
void grid15(WINDOW *win)
{	

	winReset(win);

	/* Initialize Grid */
	mvwprintw(win, 9, 0, "┝");							// left border connection
	mvwprintw(win, 9, 48, "┥");							// right border connection
	mvwprintw(win, 9, 17, "╋");							// middle border connection
	mvwprintw(win, 0, 17, "┰");							// top border connection
	mvwprintw(win, 25, 17, "┸");						// bottom border connection

	for (int i = 1; i < 17; i++)						// horizontal line connection
		mvwprintw(win, 9, i, "━");

	for (int i = 1; i < 9; i++)							// vertical line connection
		mvwprintw(win, i, 17, "┃");
	

	/* Initializing Grid Color */
	int cp = 3;
	for (int i = 18; i < 48; i = i + 2)					// from x = 18 --> 47
	{
		for (int j = 10; j < 25; j++)					// from y = 10 --> 25
		{
			if (cp == 3)								// alternate color pair
			cp = 4;
			else
			cp = 3;

			wattrset(win, COLOR_PAIR(cp));
			mvwprintw(win, j, i, "  ");
			wattroff(win, COLOR_PAIR(cp));
		}
	}

	/* Initializing vertical locations*/
	cp = 2;
	for (int i = 18; i < 48; i = i + 2)					// from x = 18 --> 47
	{
		if (cp == 3)									// alternate color pair every column
			cp = 4;
		else
			cp = 3;

		wattrset(win, COLOR_PAIR(cp));
		for (int j = 1; j < 10; j++)					// from y = 1 --> 9
		{
			mvwprintw(win, j, i, "  ");
		}
		wattroff(win, COLOR_PAIR(cp));

		mvwprintw(win, 9, i, "━━");
	}

	/* Initializing horizontal locations*/
	cp = 2;
	for (int j = 10; j < 25; j++)						// from y = 10 --> 24
	{
		if (cp == 3)									// alternate color pair every row
			cp = 4;
		else
			cp = 3;

		wattrset(win, COLOR_PAIR(cp));
		for (int i = 1; i < 17; i = i + 2)				// from x = 1 --> 16
		{
			mvwprintw(win, j, i, "  ");
		}
		wattroff(win, COLOR_PAIR(cp));

		mvwprintw(win, j, 17, "┃");
	}
	
	mvwprintw(win, 1, 5, "Nonograms");
	mvwprintw(win, 2, 6, "Level");
	mvwprintw(win, 3, 7, "15x15");
	mvwprintw(win, 5, 5, "Lives: 3");
	mvwprintw(win, 7, 5, "Hints: 3");

	wrefresh(win);

}
void levelInit(WINDOW *win, int array[15][15], int mode, int level)
{
	int yMax, xMax, xPos, yPos, count = 0;
	initializeArray(array);
	selectLevel(array, mode, level);
	int cp = 4;

	switch (mode)
    {
    case 5:
        yMax = 15;
        xMax = 28;
        break;
    case 10:
        yMax = 20;
        xMax = 38;
        break;
    case 15:
        yMax = 25;
        xMax = 48;
    default:
        break;
    }

	for (int i = 10; i < yMax; i++)
	{
		if (cp == 3)								// alternate color pair
			cp = 4;
			else
			cp = 3;
		
		wattrset(win, COLOR_PAIR(cp));
		mvwaddch(win, i, 16, 48);
		wattroff(win, COLOR_PAIR(cp));
	}
	
	cp = 4;

	for (int i = 19; i < xMax; i += 2)
	{
		if (cp == 3)								// alternate color pair
			cp = 4;
			else
			cp = 3;
		
		wattrset(win, COLOR_PAIR(cp));
		mvwaddch(win, 8, i, 48);
		wattroff(win, COLOR_PAIR(cp));
	}

	cp = 4;

	for (int i = 0; i < mode; i++)
	{
		xPos = 16;
		yPos = 10 + i;

		if (cp == 3)								// alternate color pair
			cp = 4;
			else
			cp = 3;
		
		for (int j = mode - 1; j >= 0; j--)
		{
			if (array[i][j] == 0 && count > 0)
			{
				wattrset(win, COLOR_PAIR(cp));
				if (count > 9)
				{
					count -= 10;
					mvwaddch(win, yPos, xPos - 1, 49);
					mvwaddch(win, yPos, xPos, count + 48);
					xPos = xPos - 3;
				}
				else
				{
					mvwaddch(win, yPos, xPos, count + 48);
					xPos = xPos - 2;
				}
				wattroff(win, COLOR_PAIR(cp));
				count = 0;
			}
			else if (array[i][j] == 1 && j == 0)
			{
				count++;
				wattrset(win, COLOR_PAIR(cp));
				if (count > 9)
				{
					count -= 10;
					mvwaddch(win, yPos, xPos - 1, 49);
					mvwaddch(win, yPos, xPos, count + 48);
					xPos = xPos - 3;
				}
				else
				{
					mvwaddch(win, yPos, xPos, count + 48);
					xPos = xPos - 2;
				}
				wattroff(win, COLOR_PAIR(cp));
				count = 0;
			}
			else if (array[i][j] == 1)
				count++;
		}
	}

	cp = 4;

	for (int i = 0; i < mode; i++)
	{
		xPos = 19 + 2*i;
		yPos = 8;

		if (cp == 3)								// alternate color pair
			cp = 4;
			else
			cp = 3;
		
		for (int j = mode - 1; j >= 0; j--)
		{
			if (array[j][i] == 0 && count > 0)
			{
				wattrset(win, COLOR_PAIR(cp));
				if (count > 9)
				{
					count -= 10;
					mvwaddch(win, yPos, xPos - 1, 49);
				}
				mvwaddch(win, yPos, xPos, count + 48);
				wattroff(win, COLOR_PAIR(cp));
				count = 0;
				yPos = yPos - 1;
			}
			else if (array[j][i] == 1 && j == 0)
			{
				count++;
				wattrset(win, COLOR_PAIR(cp));
				if (count > 9)
				{
					count -= 10;
					mvwaddch(win, yPos, xPos - 1, 49);
				}
				mvwaddch(win, yPos, xPos, count + 48);
				wattroff(win, COLOR_PAIR(cp));
				count = 0;
				yPos = yPos - 1;
			}
			else if (array[j][i] == 1)
				count++;
		}
	}

	if (level == 10)
	{
		mvwaddch(win, 2, 12, 49);
		mvwaddch(win, 2, 13, 48);
	}
	else
		mvwaddch(win, 2, 12, level + 48);
	wattrset(win, COLOR_PAIR(5));
    mvwaddch(win, 10, 18, ' ');
	mvwaddch(win, 10, 19, ' ');
	wmove(win, 10, 19);
    wattroff(win, COLOR_PAIR(5));
}
void movement(WINDOW *win, int mode, int level, int array[15][15])
{
	Movement * p = new Movement(win, mode, array);
	int move = 0;
	do
	{
		wrefresh(win);
		move = p -> getmv(array, mode, level);
		if (move == 'p')
			move = 199;
		
	} while ((move < 199) || (move > 200));
	if (move == 200)
	{
		Menu menu = Menu(win);
		menu.levelComplete(mode, level);
	}
}
void menu(WINDOW *win, int& mode, int& level)
{
	Menu menu = Menu(win);
	winReset(win);
	do
	{
		menu.draw(mode);
	} while (menu.handleMovement(mode, level) != 200);
}



int main()
{
	setlocale(LC_ALL, "");

	initscr();
	if(!has_colors())
	{
		mvprintw(0, 0, "This terminal does not support colours.");
		mvprintw(1, 0, "Please use another terminal.");
		refresh();
		getch();
		move(0, 0);
		refresh();
		return -1;
	}
	start_color();

	init_color(0, 0, 0, 0);				// black
	init_color(7, 1000, 1000, 1000);	// white
	init_color(1, 500, 500, 500);		// grey - light
	init_color(2, 450, 450, 450);		// grey - dark
	init_color(3, 600, 600, 600);		// grey - cursor 
	init_color(4, 220, 280, 375);		// blue
	init_color(5, 900, 415, 395);		// red
	init_color(6, 450, 590, 360);		// green

	init_pair(1, 0, 7);
	init_pair(2, 7, 0);
	init_pair(3, 7, 1);
	init_pair(4, 7, 2);
	init_pair(5, 3, 3);
	init_pair(6, 7, 4);
	init_pair(7, 7, 5);
	init_pair(8, 7, 6);

	
	/* Initialize Window */
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	int h, w, s_y, s_x;
	h = 2 + 8 + 1 + 15; 	// = 26						// border + locations + inner border + grid
	w = 2 + 16 + 1 + 30;	// = 49						// border + locations + inner border + grid
	s_y = (yMax - h)/2;
	s_x = (xMax - w)/2;

	if((yMax < h) || (xMax < w))
	{
		mvprintw(0, 0, "This terminal is not big enough (at least 49x26).");
		mvprintw(1, 0, "Please resize terminal so program can run.");
		refresh();
		getch();
		move(0, 0);
		refresh();
		return -1;
	}

	WINDOW *win = newwin(h, w, s_y, s_x);
	noecho();
	curs_set(0);
	refresh();

	box(win, 0, 0);

	start(win);
	int exitLoop = 0;
	do
	{
		int mode = 0;
		int level = 0;
		int array[15][15];

		menu(win, mode, level);

		switch (mode) {
		case 0:
			exitLoop = 1;
			break;
		case 5:
			grid5(win);
			levelInit(win, array, mode, level);
			movement(win, mode, level, array);
			break;
		case 10:
			grid10(win);
			levelInit(win, array, mode, level);
			movement(win, mode, level, array);
			break;
		case 15:
			grid15(win);
			levelInit(win, array, mode, level);
			movement(win, mode, level, array);
			break;
		default:
			break; }
	} while (exitLoop == 0);

	endwin();

	return 0;
}
