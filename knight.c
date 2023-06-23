#include "CB8x8.h"
#include "knight.h"
#include <stdio.h>

void MoveKnight(CHESSB a, int x1, int y1, int x2, int y2){
        if((x1 > 7) || (y1 > 7) || (x1 < 0) || (y1 < 0)){
                printf("Out of Bounds!!");
        }
        else if((!a[x1][y1]) || (a[x1][y1]->Charac != 2)){
                printf("No piece/Selected Wrong Piece");

        }
        else{
                if(((x2 == x1 + 1) || (x2 == x1 - 1)) && ((y2 == y1 + 2) || (y2 == y1 - 2))){
                        if(!a[x2][y2]){
                                MoveChessBoardPiece(a,x1,y1,x2,y2);
                        }
                        /*else{

                        }*/

                }
                else if((!a[x2][y2]) && ((x2 == x1 + 2) || (x2 == x1 - 2)) && ((y2 == y1 + 1) || (y2 == y1 - 1))){
                        if(!a[x2][y2]){
                                 MoveChessBoardPiece(a,x1,y1,x2,y2);
                        }
                        /*else{

                        }*/

                }
        }
}

