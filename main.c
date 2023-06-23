// Added Functions so far...
//PAWN
//ROOK
//QUEEN
//BISHOP

// Checks if the initial spot and new spot are the same color. No move is allowed.
// Checks if the player chooses their color for initial piece
// Checks if the initial spot has a piece

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "CB8x8.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"

//int turn; to make players change turns
//int move;

int main()
{

        CHESSB c;
        
        EmptyChessBoard(c);

        DefaultChessBoard(c);

        DisplayChessBoardWhite(c);
        
        DisplayChessBoardBlack(c);

    int x1, y1, x2, y2;
    while (1) {
        //checks if the move is within the board and if there's a piece at x1,y1
        //if the input is not 2 characters or is not within bounds or there's no piece at the input, then
        //give an error message, clear the input, and re loop
        printf("Enter your piece location (x1,y1): ");
        if (scanf("%d,%d", &x1, &y1) != 2 || x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || !c[x1][y1]) {
            printf("Please try again. Position not found.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        //checks to see if the user chooses the right color
        //if (c[x1][y1] && c[x1][y1]->Color == !turn)
        if (c[x1][y1] && c[x1][y1]->Color != turn){
            printf("Wrong color chosen.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        //if the color is correct, ask for the new position x2,y2
        //same condition as x1,y1 + if there's a piece at x2,y2 we need to check its color
        //if the color is the same ask user for a new move, if the color is different allow move (capture)
        if (c[x1][y1] && c[x1][y1]->Color == turn) {
            printf("Enter where you want to move the piece (x2,y2): ");
            if (scanf("%d,%d", &x2, &y2) != 2 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7 ||
                (c[x2][y2] && c[x1][y1]->Color == c[x2][y2]->Color)) {
                printf("Please try again. Position not found.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
        }

        PIECE *p = c[x1][y1];
        if (p->Charac == 0){
            MovePawn(c, x1, y1,x2, y2);
            isKingChecked(c);
        } else if (p->Charac == 1){
            MoveRook(c, x1, y1,x2, y2);
            isKingChecked(c);
        } else if (p->Charac == 3){
            MoveBishop(c, x1, y1,x2, y2);
            isKingChecked(c);
        } else if (p->Charac == 4){
            MoveKing(c, x1, y1, x2, y2);
            isKingChecked(c);
        } else if (p->Charac == 5){
            MoveQueen(c, x1, y1,x2, y2);
            isKingChecked(c);
        }
        printf("\n");
        DisplayChessBoardWhite(c);
        DisplayChessBoardBlack(c);

    }

    //DeleteChessBoard(c);

    // return 0;
}
