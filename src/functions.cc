#include "functions.hpp"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Your function definitions should go in this source file.
std::string W(char before, int i) {
    if (i == 0 || before == 'a' || before == 'o'|| before == 'u') {
        return "w";
    } 
    if (before == 'i' || before == 'e') {
        return "v";
    }
    return "\n";
    }
}
std::string Phonetics(std::string input) {
    std::string hold = "";
    for (unsigned int i = 0; i < input.size(); i++) {
        switch (tolower(input.at(i))) {
            case 'p' :
            case 'h' :
            case 'k' :
            case 'l' :
            case 'm' :
            case ' ':
            case '\'':
            case 'n' :
                hold += tolower(input.at(i));
                break;
            case 'w' :
                hold += W(tolower(input.at(i - 1)), i);
                break;
            case 'a' :
                if (i == input.size() - 1) {
                    hold += "ah";
                } else if (tolower(input.at(i + 1)) == 'i' || tolower(input.at(i + 1)) == 'e') {
                    hold += "eye";
                    i++;
                    if (i != input.size() - 1 && input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                } else if (tolower(input.at(i + 1)) == 'o' || tolower(input.at(i + 1)) == 'u') {
                    hold += "ow";
                    i++;
                    if (i != input.size() - 1 && input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                } else {
                    hold += "ah";
                    if (input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                }
                break;
            case 'e' :
                if (i == input.size() - 1) {
                    hold += "eh";
                } else if (tolower(input.at(i + 1)) == 'i') {
                    hold += "ay";
                    i++;
                    if (i != input.size() - 1 && input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                } else if (tolower(input.at(i + 1)) == 'u') {
                    hold += "eh-oo";
                    i++;
                    if (i != input.size() - 1 && input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                } else {
                    hold += "eh";
                    if (input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                }
                break;
            case 'i' :
                if (i == input.size() - 1) {
                    hold += "ee";
                } else if (tolower(input.at(i + 1)) == 'u') {
                    hold += "ew";
                    i++;
                    if (i != input.size() - 1 && input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                } else {
                    hold += "ee";
                    if (input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                }
                break;
            case 'o' :
                if (i == input.size() - 1) {
                    hold += "oh";
                } else if (tolower(input.at(i + 1)) == 'i') {
                    hold += "oi";
                    i++;
                    if (i != input.size() - 1 && input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                } else if (tolower(input.at(i + 1)) == 'u') {
                    hold += "ow";
                    i++;
                    if (i != input.size() - 1 && input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                } else {
                    hold += "oh";
                    if (input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                }
                break;
            case 'u' :
                if (i == input.size() - 1) {
                    hold += "oo";
                    i++;
                } else if (tolower(input.at(i + 1)) == 'i') {
                    hold += "ooey";
                    i++;
                    if (i != input.size() - 1 && input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                } else {
                    hold += "oo";
                    if (input.at(i + 1) != ' ' && input.at(i + 1) != '\'') {
                        hold += '-';
                    }
                }
                break; 
            default :
                cout << input << " contains a character not a part of the Hawaiian language.";
                return "";
                break;
        }
    }
    return hold;
}