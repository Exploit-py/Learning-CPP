#include <iostream>
#include <string>
#include <map> // como se fosse um dicionario
#include <vector>
#include <fstream> //para ler dados de um arquivo ou escrever
#include <ctime> // time 0
#include <cstdlib> //usando para pegar uma palavra aleatoria

std::string secret_word = " ";
std::map<char, bool> letters; // {char: bool} -> ex: {m: true}, é uma especie de dicionario!
std::vector<char> history;

bool letter_exists(char shot);
bool check_win();
bool check_lose();
void banner();
void show_errors();
void show_hits();
std::vector<std::string> read_files();
void sort_random_word();

int main(){
    bool win = false;
    bool lose = false;
    int attemps = 5;
    char shot;
    sort_random_word();
    
    while(!check_win() && check_lose()){
        banner();

        std::cout << "\nYou have: " << attemps << " more attempts!" << std::endl;

        show_errors(); // mostra as letras tentadas
        std::cout << std::endl << std::endl;

        show_hits(); // mostra os "_" caso a letra não exista, caso exista coloca um " "

        std::cout << "\n\nType one letter: ";
        std::cin >> shot;
        shot = tolower(shot);
        letters[shot] = true; //define {shot: true}

        if(letter_exists(shot)){
            system("cls");
        }else{
            history.push_back(shot);
            attemps --;
            system("cls");
        }
    }
    return 0;
}

void banner(){
    std::cout << "***********************" << std::endl;
    std::cout << "*    Hangman Game!    *" << std::endl;
    std::cout << "*                     *" << std::endl;
    std::cout << "***********************" << std::endl;
}

void sort_random_word(){
    std::vector<std::string> words = read_files();
    std::srand(time(NULL));
    int index = std::rand() % words.size();

    secret_word = words[index];
}

std::vector<std::string> read_files(){
    std::ifstream file;
    std::vector<std::string> words;
    file.open("words.txt");
    int length;
    file >> length;

    for(int i=0; i < length; i++){
        std::string word;
        file >> word;
        words.push_back(word);
    }
    file.close();
    return words;
}

void show_hits(){
    for(char letter : secret_word){
        if(letters[letter]){
            std::cout << letter << " ";
        }else{
            std::cout << "_ ";
        }
    }
}

void show_errors(){
    std::cout << "\nWrong letters: ";
    for(char letter : history){
        std::cout << letter << " ";
    }
}

bool letter_exists(char shot){
    for(char letter : secret_word){
        if(letter == shot){
            return true;
        }
    }
    return false;
}

bool check_win(){
    for(char letter : secret_word){ // caso a letra não tenha o valor true, quer dizer q ele não ganhou -> {letter: false}
        if(!letters[letter]){
            return false;
        }
    }
    banner();
    std::cout << "\nThe right word are: " << secret_word << std::endl;
    std::cout << "\nCongratulations!! You win!\n";
    system("pause");
    return true;
}

bool check_lose(){
    if(history.size() < 5){ // enquanto essa função retornar verdadeira, o jogo irá rodar.
        return true;
    }else{
        banner();
        std::cout << "\nThe right word was: " << secret_word << std::endl;
        std::cout << "\nOh man...You Lose! Try again\n";
        system("pause");
        return false;
    }
}