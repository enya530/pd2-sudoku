#include <iostream>
#include <string>
#include <time.h>
#include "Sudoku.h"
//#include "testSudoku.h"
#define MAX_CASE 100 // the Max board stored in the array
using namespace std;



int main()
{
    srand((unsigned)time(NULL));
    //testSudoku();
    //testSudoku2();
    //giveQuestion();

    Sudoku ss;
    //ss.GiveQuestion();
    //return 0;


    //Sudoku ss;
    ss.ReadIn();
    ss.Solve();
    return 0;
}


