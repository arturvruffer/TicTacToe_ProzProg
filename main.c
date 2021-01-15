#include <stdio.h>
#include <stdlib.h>

int board[9];


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
*   --Ohne Formatierung--
*/

    for (int i = 0; i < 9; i++){
        printf("%d", board[i]);

        if ((i+1) % 3 == 0){
            printf("\n");
        }
    }
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


int fieldEmpty(int field){
    if (board[field] == 0){
        return 1;
    }
    else {return 0;}
}


int main(void){
    setup();
    displayBoard();

    if (fieldEmpty(2)){
        changeArray(2, 1);
    }

    
    
    
    printf("\n");
    changeArray(0, 1);
    displayBoard();
    printf("\n");
    changeArray(5, 2);
    displayBoard();
    printf("\n");

    return 0;
}