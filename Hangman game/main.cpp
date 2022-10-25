#include <iostream>
#include <stdlib.h>
#include <unistd.h>


int main(){
    using namespace std;
    char palavra[30], letra[1], secreta[30];
    int tam, i, chances, acertos;
    bool acertou, existe;

    acertou = false;
    existe = false;
    acertos = 0;
    chances = 6;
    tam = 0;
    i = 0;

    cout << "Digite a palavra secreta!: ";
    cin >> palavra;
    system("cls");
    
    while(palavra[i] != '\0'){ //'\0' vai servir pra ignorar os espaços inutilizados do array
        i++; 
        tam++; //pegar o tamanho da string digitada
    }

    for(i = 0; i < 30; i++){
        secreta[i] = '_';
    }

    while((chances > 0) && (acertos < tam)){
        cout << "\nYou have a " << chances << " chances\n\n";
        cout << "Secret Word: ";
        for(i=0; i < tam; i++){ //mostrar as letras ou _
            cout << secreta[i];
        }
        cout << "\n\nType one letter: ";
        cin >> letra[0];

        for (i = 0; i < tam; i++) {
            if (secreta[i] == letra[0]) { //verificar se a letra ja existe / ja foi encontrada. 
                existe = true;
                break;
            }
        }
        if (!existe){ //se "existe" for negativo irá entrar no IF (se a letra não existe ele irá entrar no IF, se a letra digitada já existir ele só ira ignorar o IF)
            for (i = 0; i < tam; i++) {
                if (palavra[i] == letra[0]) {
                    acertou = true;
                    secreta[i] = palavra[i]; // copia para a palavra secreta a letra da palavra
                    acertos++;
                }
            }
        }
        if(!acertou){
            chances --;
        }
        acertou = false; //voltar o acerto pro false, pois o loop termina
        existe = false;
        system("cls");
    }
    if(acertos == tam){
        cout << "\nYou WIN!\n";
    
    }else{
        cout << "\nYou Loose!\n";
    }
    system("pause");
    return 0;
    
}