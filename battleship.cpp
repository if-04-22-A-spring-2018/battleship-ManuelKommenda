/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "battleship.h"
#include <stdbool.h>


CellContent myField[FIELDSIZE][FIELDSIZE];
CellContent opponentField[FIELDSIZE][FIELDSIZE];
CellContent guesses[FIELDSIZE][FIELDSIZE];

void load_game(){
    FILE* myFile = fopen("battleship.my","r");
    FILE* opponentFile = fopen("battleship.op","r");
    for(int i = 0; i < FIELDSIZE; i++)
    {
      for (int j = 0; j < FIELDSIZE; j++) {
        fread(&myField[i][j], 4, 1, myFile);
        fread(&opponentField[i][j], 4, 1, opponentFile);
        guesses[i][j] = Unknown;
      }
    }
    fclose(myFile);
    fclose(opponentFile);
}

CellContent get_shot(int row, int col){
  if(row >= 0 && row < FIELDSIZE && col >= 0 && col < FIELDSIZE)
  {
    return myField[row][col];
  }
  else{
    return OutOfRange;
  }
}

bool shoot(int row, int col){

  if(row < 0 || row >= FIELDSIZE || col < 0 || col >= FIELDSIZE)
  {
    return false;
  }
  for (int i = -1; i < 2; ++i) {
      for (int j = -1; j < 2; ++j) {
          if(row + i >= 0 && row + i < FIELDSIZE && col + j >= 0 && col + j < FIELDSIZE)
          {
            guesses[row + i][col + j] = opponentField[row + i][col + j];
          }
      }
  }
  return true;
}

CellContent get_my_guess(int row, int col){
  if(row >= 0 && row < FIELDSIZE && col >= 0 && col < FIELDSIZE)
  {
    return guesses[row][col];
  }
  else{
    return OutOfRange;
  }
}
