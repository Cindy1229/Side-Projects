#include "sudoku.h"

int UNSOLVED=81;
int SIZE_ROWS=9;
int SIZE_COLUMNS=9;

int main(){
    int** puzzle;
    Square*** sudoku;

    printf("hi21\n");
    puzzle=createPuzzle();

    printf("hi\n");


    sudoku=setUpPuzzle(puzzle);

    printf("hi!!\n");

    printPuzzle(sudoku);

    checkPuzzle(sudoku);

    printf("\n\n\n");

    printPuzzle(sudoku);

    return 0;

}
