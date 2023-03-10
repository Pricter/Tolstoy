#include "game.h"
#include <entry.h>

#include <core/tmemory.h>

b8 create_game(game* out_game) {
    out_game->app_config.start_pos_x = 100;
    out_game->app_config.start_pos_y = 100;
    out_game->app_config.start_width = 800;
    out_game->app_config.start_height = 600;
    out_game->app_config.name = "Tolstoy Testbed";
    out_game->update = game_update;
    out_game->render = game_render;
    out_game->initialize = game_initialize;
    out_game->on_resize = game_on_resize;

    out_game->state = tallocate(sizeof(game_state), MEMORY_TAG_GAME);
    return TRUE;
}