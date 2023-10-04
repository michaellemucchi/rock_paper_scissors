#include "inputvalidation.h"
#include "game.h"

// taken from professor butner
std::string get_valid_string(const std::string& prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line); //grabs the entire line
        std::stringstream line2parse(line);
        std::string word;
        line2parse >> word;
        if (line2parse) { //if I was able to read the number
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse) { //if there is nothing left we will fail to read it
                return word;
            }
        }
    }
}

int get_valid_input_from_player(const std::string& prompt) {
    while (true) {
        std::string input = get_valid_string(prompt); // use prompt to find choice
        for (auto& c : input) {
                c = tolower(c);
        }
        if (input.compare("r") == 0 ||
            input.compare("(r)ock") == 0 ||
            input.compare("rock") == 0) {
            return 0; // they chose rock
        } else if (input.compare("p") == 0 ||
                   input.compare("(p)aper") == 0 ||
                   input.compare("paper") == 0) {
            return 1; // they chose paper
        } else if (input.compare("s") == 0 ||
                   input.compare("(s)cissors") == 0 ||
                   input.compare("scissors") == 0) {
            return 2; // they chose scissors
        }
    } // if nothing runs, while loop executes again
}

bool ask_to_play_more(const std::string& prompt) {
    while (true) {
        std::string response = get_valid_string(prompt);
        for (auto& c : response) {
                c = tolower(c);
        } // lowercase the entire string.
        if (response.compare("n") == 0 ||
            response.compare("(n)o") == 0 ||
            response.compare("no") == 0) {
            return false;
            // return false if they don't want to play
            // anymore
        } else if (response.compare("y") == 0 ||
                   response.compare("(y)es") == 0 ||
                   response.compare("yes") == 0) {
            return true;
            // return true if they want to play more
        }
    }
}
