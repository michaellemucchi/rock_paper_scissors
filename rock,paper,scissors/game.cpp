#include "game.h"
#include "inputvalidation.h"

void play_game(std::minstd_rand& generator) {
    // result = 0 means we won
    // result = 1 means ai won
    // result = 2 means keep going
    int result = -1;
    while (result != 0 || result != 1) {
        int player_choice = get_valid_input_from_player("Enter (R)ock, (P)aper, or (S)cissors for your move: ");
        int ai_choice = get_input_from_ai(0, 2, generator);
        std::string str_ai = convert_ai_choice_to_string(ai_choice);
        std::cout << "The ai played " << str_ai << "." << std::endl;
        result = compare_choices(player_choice, ai_choice);
        if (player_choice == ai_choice) {
            std::cout << "You and the AI both played " << str_ai << "." << std::endl;
        }
        if (result == 0) {
            std::cout << "You win!" << std::endl;
            break;
        } else if (result == 1) {
            std::cout << "The AI wins :(" << std::endl;
            break;
        } else if (result == 2) {
            std::cout << "Keep playing until someone wins" << "." << std::endl;
        }
    }
}

// FROM PROF BUTNER
int get_input_from_ai(int min, int max, std::minstd_rand& generator) {
    std::uniform_int_distribution<int> dist(min, max);
    int random_num = dist(generator);
    return random_num;
}

int compare_choices(int PChoice, int AIChoice) {
    // rock = 0
    // paper = 1
    // scissors = 2
    if (PChoice == AIChoice) {
        return 2; //there was a tie
    } else if (PChoice == 0 && AIChoice == 1) {
        return 1; // ai won
    } else if (PChoice == 0 && AIChoice == 2) {
        return 0; //player  won
    } else if (PChoice == 1 && AIChoice == 0) {
        return 0; //player won
    } else if (PChoice == 1 && AIChoice == 2) {
        return 1; //ai won
    } else if (PChoice == 2 && AIChoice == 0) {
        return 1; //ai won
    } else if (PChoice == 2 && AIChoice == 1) {
        return 0; //player won
    } else {
        std::cout << "Something went horribly wrong." << std::endl;
    }
}

std::string convert_ai_choice_to_string(int ai_choice) {
    std::string outstr;
    if (ai_choice == 0) {
        outstr = "rock";
    } else if (ai_choice == 1) {
        outstr = "paper";
    } else if (ai_choice == 2) {
        outstr = "scissors";
    }
    return outstr;
}