#include "main.h"

int main() {    
    setup();
    int ch;
    Direction dir = RIGHT;
    vector<Position> snake = {{WIDTH/2, HEIGHT/2}};
    Position food = {rand()%(WIDTH-4)+2, rand()%(HEIGHT-4)+2};

    while(true){
        clear();
        drawBorder(WIDTH, HEIGHT);

        ch = getch();
        switch (ch) {
            case KEY_UP:    if (dir != DOWN) dir = UP; break;
            case KEY_DOWN:  if (dir != UP) dir = DOWN; break;
            case KEY_LEFT:  if (dir != RIGHT) dir = LEFT; break;
            case KEY_RIGHT: if (dir != LEFT) dir = RIGHT; break;
            case 'q':       teardown(); return 0;
        }

        Position newHead = snake.front();
        switch (dir) {
            case UP:    newHead.y--; break;
            case DOWN:  newHead.y++; break;
            case LEFT:  newHead.x--; break;
            case RIGHT: newHead.x++; break;
        }

        if (newHead.x <= 0 || newHead.x >= WIDTH - 1 || newHead.y <= 0 || newHead.y >= HEIGHT - 1) break;
        for (const auto& segment : snake) {
            if (segment.x == newHead.x && segment.y == newHead.y) {
                teardown();
                return 0;
            };
        }

        snake.insert(snake.begin(), newHead);
        if(newHead.x == food.x && newHead.y == food.y){

            food = {rand()%(WIDTH-4)+2, rand()%(HEIGHT-4)+2};
        }else{
            snake.pop_back();
        }

        mvaddch(food.y, food.x, '~');
        // for (const auto& segment : snake) {
        //     mvaddch(segment.y, segment.x, 'o');
        // }
        for (size_t i = 0; i < snake.size(); ++i) {
        if (i == 0) {
            mvaddch(snake[i].y, snake[i].x, 'o');
        } else {
            mvaddch(snake[i].y, snake[i].x, '+');
        }
    }
        refresh();
        usleep(100000);
    }
  
    teardown();

    return 0;
}