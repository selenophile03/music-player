#include <stdio.h>
#include "player.h"

int main() {
    MusicPlayer player;
    init_player(&player);
    
    add_song(&player, "Bohemian Rhapsody", "Queen", 354);
    add_song(&player, "Blinding Lights", "The Weeknd", 200);
    add_song(&player, "Hotel California", "Eagles", 390);

    int choice;
    do {
        display_status(&player);
        printf("1. Play\n");
        printf("2. Pause\n");
        printf("3. Next Track\n");
        printf("4. Previous Track\n");
        printf("5. Listen (Simulate 5s Playback)\n");
        printf("6. Exit\n");
        printf("Enter your control option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                play_track(&player);
                break;
            case 2:
                pause_track(&player);
                break;
            case 3:
                next_track(&player);
                break;
            case 4:
                prev_track(&player);
                break;
            case 5:
                update_time(&player);
                break;
            case 6:
                printf("\nClosing App. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
