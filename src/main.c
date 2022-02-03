#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "game_window.h"

int main(int argc, char const **argv) {
    chdir(getenv("HOME"));

    GameWindow *game_window = create_game_window();

    game_window_loop(game_window);

    return 0;
}
