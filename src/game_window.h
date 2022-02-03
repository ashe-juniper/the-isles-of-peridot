#ifndef TIOP_GAME_WINDOW_H
#define TIOP_GAME_WINDOW_H 1

typedef struct GameWindow {
    int width;
    int height;
    char const *title;
} GameWindow;

GameWindow *create_game_window();
void game_window_loop(GameWindow *game_window);

#endif
