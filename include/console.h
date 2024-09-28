#ifndef CONSOLE_H
#define CONSOLE_H

#include <ncurses.h>
#define HEIGHT 20
#define WIDTH 80

enum Direction {UP, DOWN, LEFT, RIGHT};

void setup(void);
void teardown(void);
void drawBorder(int, int);

#endif

