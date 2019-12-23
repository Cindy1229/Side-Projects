#include "sudoku.h"

Square*** setUpPuzzle(int ** puzzle){
    Square*** sudoku;
    int i,j;

    sudoku=(Square***)malloc(sizeof(Square**)*9);


    for (i = 0; i < SIZE_ROWS; i++) {

        /* malloc space for each row*/
        sudoku[i]=(Square**)malloc(sizeof(Square*)*9);

        for (j = 0; j < SIZE_COLUMNS; j++) {

            /* malloc space for each column*/
            sudoku[i][j]=(Square*)malloc(sizeof(Square)*9);

            /* assign number to each sudoku square*/
            sudoku[i][j]->number=puzzle[i][j];

            /* assign row and column information*/
            sudoku[i][j]->row=i;
            sudoku[i][j]->column=j;

            /* initialize the possible array*/
            for (int x = 0; x < SIZE_ROWS; x++) {
                sudoku[i][j]->possible[x]=0;
                sudoku[i][j]->solvable=9;
            }

            /* check the possible values for each square */
            for (size_t i = 0; i < SIZE_ROWS; i++) {
                for (size_t i = 0; i < SIZE_COLUMNS; i++) {
                    if(sudoku[i][j]->number!=0){
                        sudoku[i][j]->solvable=0;
                        updateSudoku(sudoku, i,j);
                        UNSOLVED--;
                    }
                }
            }


        }

        return sudoku;
    }

}

int updateSudoku(Square *** sudoku, int row, int column){
    int x;
    int number=sudoku[row][column]->number;

    for (size_t x = 0; x < SIZE_ROWS; x++) {
        if(sudoku[x][column]->possible[number-1]==0){
            sudoku[x][column]->solvable--;
        }
        sudoku[x][column]->possible[number-1]=1;
    }

    for (size_t x = 0; x < SIZE_COLUMNS; x++) {
        if(sudoku[row][x]->possible[number-1]==0){
            sudoku[row][x]->solvable--;
        }
        sudoku[row][x]->possible[number-1]=1;
    }

    return 1;
}

int checkPuzzle(Square*** sudoku){
    int i,j,x;

    for (size_t i = 0; i < SIZE_ROWS; i++) {
        for (size_t j = 0; j < SIZE_COLUMNS; j++) {
            if(sudoku[i][j]->solvable==1){
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku,i,j);
            }
        }
    }
    return 1;
}





int** createPuzzle(){
    int ** puzzle;
    int i,j;
    int array[9][9]={0,1,9, 0,0,2, 0,0,0,
                   4,7,0, 6,9,0, 0,0,1,
                   0,0,0, 4,0,0, 0,9,0,

                   8,9,4, 5,0,7, 0,0,0,
                   0,0,0, 0,0,0, 0,0,0,
                   0,0,0, 2,0,1, 9,5,8,

                   0,5,0, 0,0,6, 0,0,0,
                   6,0,0, 0,2,8, 0,7,9,
                   0,0,0, 1,0,0, 8,6,0,
                   };

    puzzle=(int**)malloc(sizeof(int*)*9);


    for (size_t i = 0; i < SIZE_ROWS; i++) {
        puzzle[i]=(int*)malloc(sizeof(int)*9);
        for (size_t j = 0; j < SIZE_COLUMNS; j++) {
            puzzle[i][j]=array[i][j];
        }
    }
    return puzzle;
}

/* print the puzzle */
void printPuzzle(Square*** puzzle){
    int i, j;

    printf("---------------------------\n");
    for (size_t i = 0; i < SIZE_ROWS; i++) {

        printf("|");
        for (size_t j = 0; j < SIZE_COLUMNS; j++) {

            printf("% d ", puzzle[i][j]->number);
            if((j+1)%3==0){
                printf("|");
            }
        }
        printf("\n");
        if((i+1)%3==0){
            printf("---------------------------\n");
        }
    }
}
