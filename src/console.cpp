#include "main.h"

void setup() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    timeout(5);
    curs_set(0);
}   

void teardown() {
    curs_set(1);
    endwin();
}  

void drawBorder(int width, int height) {
    for (int i = 0; i < width; ++i) {
        mvaddch(0, i, '-');
        mvaddch(height - 1, i, '-');
    }

    for (int i = 1; i < height - 1; ++i) {
        mvaddch(i, 0, '|');
        mvaddch(i, width - 1, '|');
    }

    mvaddch(0, 0, '+');
    mvaddch(0, width - 1, '+');
    mvaddch(height - 1, 0, '+');
    mvaddch(height - 1, width - 1, '+');
}