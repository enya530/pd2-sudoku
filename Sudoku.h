/* NCKU Course C++ Project01 Sudoku
Note: this is the head file for Class in Sudoku project
*/

#include <iostream>
#include <cstdlib> // for function exit() and srand()
using namespace std;


/* Sudoku 12x12 with Dark regions */
class Sudoku {
    public:
        Sudoku();
        Sudoku(const int init_map[]);
        void setMap(const int set_map[]);
        int getElement(int index);
        void setElement(int index, int value);
        int getFirstZeroIndex();
        void printBoard();
        Sudoku copyBoard();
        bool isValid();
        bool isCorrect();
        bool isEqual(Sudoku su);
        void GiveQuestion();
        int Solve();
        int Solve(bool printStat);
        void ReadIn();
        static const int sudokuSize = 144;
        int num_sol;
    private:
        bool checkRow(int arr[]);
        bool checkCell(int arr[]);
        bool checkLegalRow(int arr[]);
        bool checkLegalCell(int arr[]);
        void findSolution(Sudoku question, Sudoku &answer);
        int map[sudokuSize];
        //int num_sol;
};

