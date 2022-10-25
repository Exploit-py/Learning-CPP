#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

int main(){
    srand(time(0));  // Seed definido para fazer a operação matemática devolver um valor aleatório.
    int PC;
    int partidas;
    int player_number;
    char player_choice[2];
    string winner;
    int resultado, placar_player, placar_PC;
    
    partidas = 6;
    placar_player = 0;
    placar_PC = 0;

    while(partidas > 0){
        PC = rand();

        cout << "\nType one number: ";
        cin >> player_number;
        cout << "\n[P]ar\n[I]mpar\n>>> ";
        cin >> player_choice;

        resultado = (player_number + PC) % 2; //0 par 1 impar 
        if((resultado == 0) && (player_choice[0] == 'p') || (resultado == 0) && (player_choice[0] == 'P')){
            placar_player++;
            partidas--;
            system("cls");
            cout << "Player WIN!";
        }
        else if((resultado == 0) && (player_choice[0] == 'i') || (resultado == 0) && (player_choice[0] == 'I')){
            placar_player++;
            partidas--;
            system("cls");
            cout << "Player WIN!";
        }
        else{
            placar_PC ++;
            partidas --;
            system("cls");
            cout << "PC WIN!";
        }
        cout << "\n------SCORE------\n";
        cout << partidas << " Rounds left\n\n";
        cout << "Player: " << placar_player << "\nPC: " << placar_PC;
        cout << "\n-----------------";
    }

    system("cls");
    cout << "\n------SCORE------\n";
    cout << partidas << " Rounds left\n\n";
    cout << "Player: " << placar_player << "\nPC: " << placar_PC;
    cout << "\n-----------------";
    if(placar_player > placar_PC){
        winner = "Player";
    }else if(placar_PC > placar_player){
        winner = "PC";
    }else{
        winner = "Draw";
    }
    cout << "\nWinner: " << winner << endl;
    system("pause");
    return 0; 
}