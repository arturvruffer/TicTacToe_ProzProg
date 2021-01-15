#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LEN 100  //Länge des Input-Buffers

//Variablen
    int board[9];
    int gameMode = 0;       //0 = Nicht festgelegt; 1 = Spieler g. Spieler; 2 = Spieler g. Computer
    int score[2] = {0, 0};  //Speichert den Spielstand
    int gameRunning;        //Gibt an, ob eine Spielrunde im Gange ist. 0 = false; 1 = true
    int fieldInput;         //Temporärer Speicher für das eingegebene Spielfeld

int setup(){
/*  Füllt den Board-Array mit Leerzeichen
*   
*/
    for (int i = 0; i < 9; i++){
        board[i] = 0;
    }
}


int displayBoard(){
/*  Gibt das aktuelle Spielfeld in der Konsole aus.
*/
    printf("     |     |     \n");
    printf("  %d  |  %d  |  %d  \n", board[0], board[1], board[2]);
    printf("-----|-----|----- \n");
    printf("  %d  |  %d  |  %d  \n", board[3], board[4], board[5]);
    printf("-----|-----|----- \n");
    printf("  %d  |  %d  |  %d  \n", board[6], board[7], board[8]);
    printf("     |     |     \n");
}


int changeArray(int field, int player){
/*  Füllt das gespielte Feld mit
*       1 = Spieler 1
*       2 = Spieler 2
*   
*   Argumente:
*       field = Index des zu ändernden Feldes
*       player = Nummer des Spielers
*/
    board[field] = player;
}


int checkMove(int field){
/*  Prüft, ob das angegebene Feld bereits bespielt wurde.

    Argument:
        field = Index des zu prüfenden Feldes
    
    Return:
        0 = false = Feld nicht bespielbar
        1 = true = Feld bespielbar 
*/

    if (board[field] == 0){
        return 1;
    }
    else {return 0;}
}

int makeMove(int player){
/*  Fragt den Spieler nach dem Feld, das er bespielen möchte.
    Prüft, ob der Zug erlaubt ist.

    Argumente:
        player = Spieler, der am Zug ist
*/
    do
    {
        printf("Welches Feld moechtest du bespielen?\n");
  /*       printf("    1  2  3\n");
        printf("    4  5  6\n");
        printf("    7  8  9\n"); */
        scanf("%d", &fieldInput);
    } while (fieldInput < 0 || fieldInput > 10);
    
    //Zug wird überprüft. Wenn nicht zulässig: Rekursiver Funktionsaufruf.
    if (checkMove(fieldInput - 1)){
        changeArray(fieldInput - 1, player);
    }
    else {
        displayBoard();
        printf("Das gewählte Feld ist belegt!");
        makeMove(player);
    }
}


int main(void){
    char buffer[BUFFER_LEN];    //Input-Buffer

    setup();
    displayBoard();


    //Hauptspielschleife
    for (int i = 0; i < 1; i++){
        
        //Spielmodus einstellen
        if (gameMode == 0){
            do
            {
                printf("Spielmodus eingeben:\n");
                printf("1) Spieler gegen Spieler        2) Spieler gegen Computer\n");
                scanf("%d", &gameMode);
            } while (gameMode != 1 && gameMode != 2);
            printf("Spielmodus %d ausgewaehlt!\n\n", gameMode);
        }

        //Abwechselnde Züge der Spieler (S g. S-Modus)
        if (gameMode == 1){
            for (int j = 0; j < 5; j++){
                displayBoard();
                printf("Spieler %d ist an der Reihe!\n", j % 2 + 1);
                makeMove(j % 2 + 1);
            }
        }
        else if (gameMode == 2){
            //Spieler gegen Computer Spielmodus
        }
    }
    
    

    return 0;
}