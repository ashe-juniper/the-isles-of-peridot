#include <stdlib.h>
#include "raylib.h"
#include "game_window.h"

GameWindow *create_game_window(void) {
    GameWindow *game_window = malloc(sizeof(GameWindow));

    game_window->width = 640;
    game_window->height = 480;
    game_window->title = "The Isles of Peridot";

    InitWindow(game_window->width, game_window->height, game_window->title);

    return game_window;
}

void game_window_loop(GameWindow *game_window) {
    Texture2D texture = LoadTexture(".the-isles-of-peridot/assets/sprites/normal.png");

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(texture, game_window->width/2 - texture.width/2, game_window->height/2 - texture.height/2, WHITE);

            DrawText("this IS a texture!", 360, 370, 10, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    free(game_window);
}
