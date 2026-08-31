#include <stdio.h>
#include <string.h>
#include "player.h"

void init_player(MusicPlayer *player) {
    player->count = 0;
    player->current_index = -1;
    player->is_playing = 0;
    player->elapsed_time = 0;
}

void add_song(MusicPlayer *player, const char *title, const char *artist, int duration) {
    if (player->count >= MAX_SONGS) {
        printf("\nQueue is full!\n");
        return;
    }
    strcpy(player->queue[player->count].title, title);
    strcpy(player->queue[player->count].artist, artist);
    player->queue[player->count].duration = duration;
    
    if (player->current_index == -1) {
        player->current_index = 0;
    }
    player->count++;
    printf("\nAdded: %s by %s\n", title, artist);
}

void display_status(MusicPlayer *player) {
    printf("\n===================================\n");
    printf("        CONSOLE MUSIC HUB          \n");
    printf("===================================\n");
    
    if (player->count == 0 || player->current_index == -1) {
        printf(" Queue is empty. Please add tracks.\n");
        printf("===================================\n");
        return;
    }

    Song current = player->queue[player->current_index];
    printf(" NOW PLAYING: %s\n", current.title);
    printf(" ARTIST:      %s\n", current.artist);
    printf(" STATUS:      [%s]\n", player->is_playing ? "PLAYING" : "PAUSED");
    printf(" TIME:        %02d:%02d / %02d:%02d\n", 
            player->elapsed_time / 60, player->elapsed_time % 60,
            current.duration / 60, current.duration % 60);
    printf("===================================\n");
    printf(" Track %d of %d\n", player->current_index + 1, player->count);
    printf("===================================\n");
}

void play_track(MusicPlayer *player) {
    if (player->count == 0) return;
    player->is_playing = 1;
}

void pause_track(MusicPlayer *player) {
    player->is_playing = 0;
}

void next_track(MusicPlayer *player) {
    if (player->count == 0) return;
    if (player->current_index < player->count - 1) {
        player->current_index++;
        player->elapsed_time = 0;
    } else {
        printf("\nReached the end of the playlist.\n");
    }
}

void prev_track(MusicPlayer *player) {
    if (player->count == 0) return;
    if (player->current_index > 0) {
        player->current_index--;
        player->elapsed_time = 0;
    } else {
        printf("\nAlready at the first track.\n");
    }
}

void update_time(MusicPlayer *player) {
    if (player->is_playing && player->current_index != -1) {
        if (player->elapsed_time < player->queue[player->current_index].duration) {
            player->elapsed_time += 5; 
        } else {
            next_track(player);
        }
    }
}
