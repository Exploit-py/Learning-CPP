#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

void banner(std::string nickname);
bool easy_game(std::string nickname, int wins, int loses);
bool game_config(std::string nickname, char difficulty, int wins, int loses);
bool medium_game(std::string nickname, int wins, int loses);
bool hard_game(std::string nickname, int wins, int loses);


int main(){
    std::string nickname;
    char difficulty;
    char reset = 'y';
    int wins = 0;
    int loses = 0;

    std::cout << "Set your nickname: ";
    std::getline(std::cin, nickname);
    if(nickname.size() <= 0){
        nickname = "Guest";
    }

    while(reset == 'y'){
        std::cout << "\nChoose a Difficulty\n[e]asy\n[m]edium\n[h]ard\n>>> ";
        std::cin >> difficulty;
        if(game_config(nickname, difficulty, wins, loses)){
            wins++;
        }else{
            system("cls");
            banner(nickname);
            std::cout << "\nYou Lose!\n";
            loses++;
        };
        std::cout << "Play again? [y/n]: ";
        std::cin >> reset;
    }
    system("pause");
    return 0;
}

void banner(std::string nickname){ // show banner
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*\tWelcome to the guessing game!\t *" << std::endl;
    std::cout << "\t\t  " +nickname << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "******************************************" << std::endl;
}

bool game_config(std::string nickname, char difficulty, int wins, int loses){ // settings 
    switch(difficulty){
        case 'e':
            system("cls");
            banner(nickname);
            std::cout << "\nYou selected [EASY Mode]\n";
            if(easy_game(nickname, wins, loses)){
                return true;
            }else{
                return false;
            };
            break;

    case 'm':
        system("cls");
        banner(nickname);
        std::cout << "\nYou selected [MEDIUM Mode]\n";
        if(medium_game(nickname, wins, loses)){
            return true;
        }else{
            return false;
        };
        break;
        
    case 'h':
        system("cls");
        banner(nickname);
        std::cout << "\nYou selected [HARD Mode]\n";
        if(hard_game(nickname, wins, loses)){
            return true;
        }else{
            return false;
        };
        break;

    default:
        break;
    }
}

bool easy_game(std::string nickname, int wins, int loses){
    srand(time(0));
    const int SECRET_NUMBER = rand() % 100;
    int easy_limit = 25;
    long long int number;
    int attempts = 0;
    bool end = false;
    bool win = false;
    std::vector<int> history;

    
    while((!end) && (easy_limit > 0)){
        std::cout << "\nNickname: " + nickname << "\nWins: " << wins << "\nLoses: " << loses << "\nAttempts: " << attempts << "\n\nYou have: " << easy_limit << " more attempts" << std::endl;
        std::cout << "\nTry type a correct number: ";
        std::cin >> number;

        if(number < SECRET_NUMBER){
            system("cls");
            banner(nickname);
            std::cout << "\nTry a Number [+ greater +] than: " << number << std::endl;

        }else if(number > SECRET_NUMBER){
            system("cls");
            banner(nickname);
            std::cout << "\nTry a Number [- lesser -] than: " << number << std::endl;

        }else{
            end = true;
            win = true;
            system("cls");
            banner(nickname);
            std::cout << "\nCorrect Number: " << SECRET_NUMBER << " \n";
            std::cout << nickname << " won with: " << attempts << " attempts!!\n" << std::endl;
        }
        attempts++;
        easy_limit --;
        history.push_back(number);
        std::cout << "\nHistory: ";
        for(auto i: history){
            std::cout << i << ", ";
        }
        std::cout << "\n";
    }

    return win;
}

bool medium_game(std::string nickname, int wins, int loses){
    srand(time(0));
    const int SECRET_NUMBER = rand() % 100;
    int medium_limit = 15;
    long long int number;
    int attempts = 0;
    bool end = false;
    bool win = false;
    std::vector<int> history;
    
    while((!end) && (medium_limit > 0)){
        std::cout << "\nNickname: " + nickname << "\nWins: " << wins << "\nLoses: " << loses << "\nAttempts: " << attempts << "\n\nYou have: " << medium_limit << " more attempts" << std::endl;
        std::cout << "\nTry type a correct number: ";
        std::cin >> number;

        if(number < SECRET_NUMBER){
            system("cls");
            banner(nickname);
            std::cout << "\nTry a Number [+ greater +] than: " << number << std::endl;

        }else if(number > SECRET_NUMBER){
            system("cls");
            banner(nickname);
            std::cout << "\nTry a Number [- lesser -] than: " << number << std::endl;

        }else{
            end = true;
            win = true;
            system("cls");
            banner(nickname);
            std::cout << "\nCorrect Number: " << SECRET_NUMBER << " \n";
            std::cout << nickname << " won with: " << attempts << " attempts!!\n" << std::endl;
        }
        attempts++;
        medium_limit--;
        history.push_back(number);
        std::cout << "\nHistory: ";
        for(auto i: history){
            std::cout << i << ", ";
        }
        std::cout << "\n";
    }

    return win;
}

bool hard_game(std::string nickname, int wins, int loses){
    srand(time(0));
    const int SECRET_NUMBER = rand() % 100;
    int hard_limit = 6;
    long long int number;
    int attempts = 0;
    bool end = false;
    bool win = false;
    std::vector<int> history;
    
    while((!end) && (hard_limit > 0)){
        std::cout << "\nNickname: " + nickname << "\nWins: " << wins << "\nLoses: " << loses << "\nAttempts: " << attempts << "\n\nYou have: " << hard_limit << " more attempts" << std::endl;
        std::cout << "\nTry type a correct number: ";
        std::cin >> number;

        if(number < SECRET_NUMBER){
            system("cls");
            banner(nickname);
            std::cout << "\nTry a Number [+ greater +] than: " << number << std::endl;

        }else if(number > SECRET_NUMBER){
            system("cls");
            banner(nickname);
            std::cout << "\nTry a Number [- lesser -] than: " << number << std::endl;

        }else{
            end = true;
            win = true;
            system("cls");
            banner(nickname);
            std::cout << "\nCorrect Number: " << SECRET_NUMBER << " \n";
            std::cout << nickname << " won with: " << attempts << " attempts!!\n" << std::endl;
        }
        
        attempts++;
        hard_limit--;
        history.push_back(number);
        std::cout << "\nHistory: ";
        for(auto i: history){
            std::cout << i << ", ";
        }
        std::cout << "\n";
    }

    return win;
}