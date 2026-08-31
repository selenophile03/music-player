#ifndef PLAYER_H
#define PLAYER_H

#define MAX_SONGS 10
#define MAX_NAME 50

typedef struct {
    char title[MAX_NAME];
    char artist[MAX_NAME];
    int duration; 
} Song;

typedef struct {
    Song queue[MAX_SONGS];
    int count;
    int current_index;
    int is_playing;
    int elapsed_time;
} MusicPlayer;

void init_player(MusicPlayer *player);
void add_song(MusicPlayer *player, const char *title, const char *artist, int duration);
void display_status(MusicPlayer *player);
void play_track(MusicPlayer *player);
void pause_track(MusicPlayer *player);
void next_track(MusicPlayer *player);
void prev_track(MusicPlayer *player);
void update_time(MusicPlayer *player);

#endif
