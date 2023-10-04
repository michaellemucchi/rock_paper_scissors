//
// Created by Michael Lemucchi on 4/23/22.
//

#ifndef INC_RockPaperScissors_GAME_H
#define INC_RockPaperScissors_GAME_H

    #include <iostream>
    #include <random>
    #include <sstream>
    #include <cctype>
    #include <string>

    void play_game(std::minstd_rand& generator);
    int compare_choices(int PChoice, int AIChoice);
    int get_input_from_ai(int min, int max, std::minstd_rand& generator);
    std::string convert_ai_choice_to_string(int ai_choice);


#endif //INC_RockPaperScissors_GAME_H
