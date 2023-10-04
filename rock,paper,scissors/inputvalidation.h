//
// Created by Michael Lemucchi on 4/23/22.
//

#ifndef INC_RockPaperScissors_INPUTVALIDATION_H
#define INC_RockPaperScissors_INPUTVALIDATION_H

    #include <random>
    #include <iostream>
    #include <cctype>
    #include <string>

    std::string get_valid_string(const std::string& prompt);
    int get_valid_input_from_player(const std::string& prompt);
    bool ask_to_play_more(const std::string& prompt);

#endif //INC_RockPaperScissors_INPUTVALIDATION_H
