#include "game.h"
#include "inputvalidation.h"

int main(int argc, char** argv) {
    int seed = std::stoi(argv[1]);
    std::minstd_rand generator(seed);
    bool is_keep_playing;
    do {
        play_game(generator);
        is_keep_playing = ask_to_play_more("Would you like to replay the game?\nEnter (Y)es or (N)o: ");
    } while (is_keep_playing);
    return 0;
}