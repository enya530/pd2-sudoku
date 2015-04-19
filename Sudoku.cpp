/*
note:
This .cpp file implement the body of member function of
the class define in the head file
*/

#include "Sudoku.h"
#include <fstream>
using namespace std;

/* Helper Function */
void arrayPrint(int arr[], int len){
    for(int idx = 0; idx < len; idx++){
        cout << arr[idx] << " ";
	}
	cout << endl;
}

int randNum(int lw, int up){
    /* generate random number following the uniform distribution [lw, up] */
    return rand() % (up - lw + 1) + lw;
} // end function rand_num

 void arraySwap(int arr[], int idx1, int idx2){
     int temp = arr[idx1];
     arr[idx1] = arr[idx2];
     arr[idx2] = temp;
 }


/* Sudoku */
Sudoku::Sudoku(){
    /* constructor */
	for (int i = 0; i < sudokuSize; i++){
		map[i] = 0;
	} // end for loop
} // end member func Sudoku

Sudoku::Sudoku(const int init_map[]){
    /* constructor */

	for (int idx = 0; idx < sudokuSize; idx += 1){
		map[idx] = init_map[idx];
	} // end for loop
} // end Sudoku constructor

void Sudoku::setMap(const int init_map[]){
    /* constructor */
	for (int idx = 0; idx < sudokuSize; idx += 1){
		map[idx] = init_map[idx];
	} // end for loop
} // end Sudoku constructor

int Sudoku::getElement(int index){
    /* Get function of the Sudoku board */
	return map[index];
} // end member func getElement

void Sudoku::setElement(int index, int value){
    map[index] = value;
} // end function setElement

int Sudoku::getFirstZeroIndex(){
    /* Scan through Sudoku Board row by row; return index of
    the first zero(blank entry); return -1 otherwise */
    for(int idx = 0; idx < sudokuSize; idx += 1){
        if(map[idx] == 0){
            return idx;
        } // end if
    } // end for loop

    return -1;
};

void Sudoku::printBoard(){
    /* Layout function of the Sudoku board */
    //cout << "======================================" << endl;

    for (int idx = 0; idx < sudokuSize; idx++){
        cout << map[idx] << " ";
        if (idx % 12 == 11){
            cout << "\n";
        } // end if
    } // end for loop

    //cout << "======================================\n" << endl;
}

bool Sudoku::checkRow(int arr[]){
    int arr_unity[10];

    // initialize to zero
    for (int idx = 0; idx < 10; idx += 1){
        arr_unity[idx] = 0;
    } // end for loop

    // count each number
    for (int idx = 0; idx < 12; idx += 1){
        if (arr[idx] == -1){
            arr_unity[9] += 1;
        } else {
            arr_unity[arr[idx] - 1] += 1;
        } // end if-else
    } // end for loop

    // check counting result
    if (arr_unity[9] != 3){
        return false;
    } // end if

    for (int idx = 0; idx < 9; idx += 1){
        if(arr_unity[idx] != 1){
            return false;
        } // end if
    } // end for loop

    return true;
} // end function checkRow

bool Sudoku::checkCell(int arr[]){
    int arr_unity[10];

    // initialize to zero
    for (int idx = 0; idx < 10; idx += 1){
        arr_unity[idx] = 0;
    } // end for loop

    // count each number
    for (int idx = 0; idx < 9; idx += 1){
        if (arr[idx] == -1){
            arr_unity[9] += 1;
        } else {
            arr_unity[arr[idx] - 1] += 1;
        } // end if-else
    } // end for loop

    // check counting result
    if (arr_unity[9] == 9){
        // case 1: all is "-1"
        return true;
    } else{
        // case 2: each 1-9 appear only once
        for (int idx = 0; idx < 9; idx += 1){
            if(arr_unity[idx] != 1){
                return false;
            } // end if
        } // end for loop
        return true;
    } // end if-else
} // end function checkRow

bool Sudoku::isCorrect(){
    /* Using the member function checkUnity, check if all the rows,
    columns and cells meet the criteria of the finished Sudoku board */

	bool check_result;
	int check_arr[12];
	int location;

    for (int i = 0; i < 12; i+=1){
        check_arr[i] = 0;
    }

	/* Check rows */
	for (int i = 0; i < 144; i += 12){
		for (int j = 0; j < 12; j++){
			check_arr[j] = map[i + j];
		} // end inner for loop

		check_result = checkRow(check_arr);
		if (check_result == false){
			return false;
		} // end if
	} // end outer for loop

	/* Check Columns */
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++){
			check_arr[j] = map[i + 12 * j];
		} // end inner for loop

		/* Check sudoku array */
		check_result = checkRow(check_arr);
		if (check_result == false){
			return false;
		} // end if

	} // end outer for loop

	/* Check Cells */
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++){
			location = 36 * (i / 3) + 3 * (i % 3) + 12 * (j / 3) + (j % 3);
			check_arr[j] = map[location];
		} // end inner for loop

		/* Check sudoku array */
		check_result = checkCell(check_arr);
		if (check_result == false){
			return false;
		} // end if

	} // end outer for loop

	/* If rows, columns and cells are checked and passed */
	return true;
} // end function isCorrect

bool Sudoku::checkLegalRow(int arr[]){
    int arr_unity[10];

    // initialize to zero
    for (int idx = 0; idx < 10; idx += 1){
        arr_unity[idx] = 0;
    } // end for loop

    // count each number
    for (int idx = 0; idx < 12; idx += 1){
        if (arr[idx] == -1){
            arr_unity[9] += 1;
        } else {
            arr_unity[arr[idx] - 1] += 1;
        } // end if-else
    } // end for loop

    // check counting result
    if (arr_unity[9] != 3){
        return false;
    } // end if

    for (int idx = 0; idx < 9; idx += 1){
        if(arr_unity[idx] > 1){
            return false;
        } // end if
    } // end for loop

    return true;
} // end function checkRow

bool Sudoku::checkLegalCell(int arr[]){
    int arr_unity[10];

    // initialize to zero
    for (int idx = 0; idx < 10; idx += 1){
        arr_unity[idx] = 0;
    } // end for loop

    // count each number
    for (int idx = 0; idx < 9; idx += 1){
        if (arr[idx] == -1){
            arr_unity[9] += 1;
        } else {
            arr_unity[arr[idx] - 1] += 1;
        } // end if-else
    } // end for loop

    // check counting result
    if (arr_unity[9] == 9){
        // case 1: all is "-1"
        return true;
    } else{
        // case 2: each 1-9 appear only once
        for (int idx = 0; idx < 9; idx += 1){
            if(arr_unity[idx] > 1){
                return false;
            } // end if
        } // end for loop
        return true;
    } // end if-else
} // end function checkRow

bool Sudoku::isValid(){
    /* Using the member function checkUnity, check if all the rows,
    columns and cells meet the criteria of the finished Sudoku board */

	bool check_result;
	int check_arr[12];
	int location;

    for (int i = 0; i < 12; i+=1){
        check_arr[i] = 0;
    }

	/* Check rows */
	for (int i = 0; i < 144; i += 12){
		for (int j = 0; j < 12; j++){
			check_arr[j] = map[i + j];
		} // end inner for loop

		check_result = checkLegalRow(check_arr);
		if (check_result == false){
			return false;
		} // end if
	} // end outer for loop

	/* Check Columns */
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++){
			check_arr[j] = map[i + 12 * j];
		} // end inner for loop

		/* Check sudoku array */
		check_result = checkLegalRow(check_arr);
		if (check_result == false){
			return false;
		} // end if

	} // end outer for loop

	/* Check Cells */
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++){
			location = 36 * (i / 3) + 3 * (i % 3) + 12 * (j / 3) + (j % 3);
			check_arr[j] = map[location];
		} // end inner for loop

		/* Check sudoku array */
		check_result = checkLegalCell(check_arr);
		if (check_result == false){
			return false;
		} // end if

	} // end outer for loop

	/* If rows, columns and cells are checked and passed */
	return true;
} // end function isCorrect

bool Sudoku::isEqual(Sudoku su){
    /* Check if input board is equal to the board */
    for (int idx = 0; idx < sudokuSize; idx += 1){
        if (map[idx] != su.getElement(idx)){
            return false;
        } // end if
    } // end for loop

    return true; // all elements are the same
}

bool Sudoku::findSolution(Sudoku question, Sudoku &answer){
    /* Recursive function */
    int firstZero;
    firstZero = question.getFirstZeroIndex();

    if (firstZero == -1){
        /* Base Case */
        if (question.isCorrect()){
            answer = question;
            return true;
        } else {
            return false;
        } // end inner if-else

    } else {
        /* Recursive Case */
        for (int num = 1; num <= 9; num += 1){
            // add number to the blank
            question.setElement(firstZero, num);

            // if the board is not valid, change the number
            if (!question.isValid()){
                continue;
            } // end inner if

            // recursive solving
            if (question.findSolution(question, answer)){
                return true;
            } // end inner if

        } // end for loop
    // the board cannot be solved
    return false;
    } // end outer if-else
} // end function findSolution

int Sudoku::Solve(){
    int num_sol = 0;
    Sudoku su = Sudoku(map); // copy
    Sudoku ans = Sudoku();   // answer
    //printBoard();
    // solve and count number of solutions
    num_sol += findSolution(su, ans);

    // decide whether print out the number of solution or not
    if (num_sol == 0){
        cout << num_sol << endl;

    } else if (num_sol == 1){
        cout << 1 << endl;

        for (int idx = 0; idx < sudokuSize; idx += 1){
            map[idx] = ans.getElement(idx);
        } // end for loop

        printBoard();
    } else {
        cout << 2 << endl;
    }// end if


    return num_sol;

} // end function solve

int Sudoku::Solve(bool printStat){
    int num_sol = 0;
    Sudoku su = Sudoku(map); // copy
    Sudoku ans = Sudoku();   // answer

    // solve and count number of solutions
    num_sol += findSolution(su, ans);

    // decide whether print out the number of solution or not
    if (printStat){
        if (num_sol > 1){
            cout << 2 << endl;
        } else {
            cout << num_sol << endl;
        } // end if-else
    } // end outer if



    // record the answer if there is one solution only
    if (num_sol == 1){
        for (int idx = 0; idx < sudokuSize; idx += 1){
            map[idx] = ans.getElement(idx);
        } // end for loop
    } // end if

    return num_sol;

} // end function solve

Sudoku Sudoku::copyBoard(){
    return Sudoku(map);
} // end function copyBoard

void Sudoku::GiveQuestion(){
    /* giveQuestion returns a Sudoku board */
    Sudoku question;

    // number substitution map
    int num_map[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Seed map for 12x12
    int seed_map[sudokuSize] = {4, 2, 6, 8, 7, 3, 9, 5, 1, -1, -1, -1,
                                   8, 7, 3, 9, 5, 1, 6, 2, 4, -1, -1, -1,
                                   9, 5, 1, 6, 2, 4, 8, 7, 3, -1, -1, -1,
                                   -1, -1, -1, 1, 3, 2, 4, 8, 7, 9, 5, 6,
                                   -1, -1, -1, 7, 8, 5, 1, 9, 6, 4, 2, 3,
                                   -1, -1, -1, 4, 9, 6, 2, 3, 5, 8, 7, 1,
                                   1, 3, 7, 2, 4, 8, -1, -1, -1, 6, 9, 5,
                                   2, 8, 4, 5, 6, 9, -1, -1, -1, 1, 3, 7,
                                   6, 9, 5, 3, 1, 7, -1, -1, -1, 2, 8, 4,
                                   3, 1, 2, -1, -1, -1, 7, 4, 8, 5, 6, 9,
                                   7, 4, 8, -1, -1, -1, 5, 6, 9, 3, 1, 2,
                                   5, 6, 9, -1, -1, -1, 3, 1, 2, 7, 4, 8};

    question.setMap(seed_map);

    //cout << "Initial Board" << endl;
    //question.printBoard();

    // create a random number map for substitution
    //cout << "Substitution Map: " << endl;
    //arrayPrint(num_map, 9);

    int idx2 = 0;
    for (int idx1 = 0; idx1 < 9; idx1 += 1){
        idx2 = randNum(0, 8);
        arraySwap(num_map, idx1, idx2);
    } // end for loop

    //arrayPrint(num_map, 9);
    //cout << endl;

    // substitute the board
    int entry = 0;
    for (int idx = 0; idx < sudokuSize; idx += 1){
        entry = question.getElement(idx);
        if(entry != -1){
            question.setElement(idx, num_map[entry - 1]);
        } // end if
    } // end for loop

    //cout << "After substitution" << endl;
    //question.printBoard();

    // random create the number of blanks
    int total_holes = 0;
    int num_hole = 0;
    int idx;
    int num_sol = 0;

    do{
        total_holes = randNum(1, 50);
        //cout << "Number of holes: " << total_holes << endl;

        // create blank in the Sudoku board

        while (num_hole < total_holes){
            // randomly choose an entry
            idx = randNum(0, question.sudokuSize);

            if (question.getElement(idx) != -1 && question.getElement(idx) != 0){
                question.setElement(idx, 0);
                num_hole += 1;
            } // end if
        } // end while loop

        //cout << "Result Question: " << endl;
        //question.printBoard();

        num_sol = question.copyBoard().Solve(false);
        //cout << "Number of Solutions: " << num_sol << endl;
     } while (num_sol != 1);

     // record the answer
     for (int idx = 0; idx < sudokuSize; idx += 1){
         map[idx] = question.getElement(idx);
     } // end for loop

     // print out the question
     question.printBoard();

} // end function giveQuestion

void Sudoku::ReadIn(){
    /* import 12x12 sudoku board*/

    string fileName;

    // prompt user to input the file
    //cout << "Please input you Sudoku file name: ";
    //cin >> fileName;

    /* Open File and Check */
    /*
    ifstream inFile(fileName.c_str(), ios::in);
    // Note:
    //    The standard streams doesn't accept a standard string,
    //    only c-string! So pass the string using c_str()

    //Ref:
f(!inFile){
        cerr << "Failed opening" << endl;
        exit(1);
    } // end if
    */
    // -------------------------------------------------------
    /* Construct Sudokus*/
    // the number of Sudoku boards in infile.txt

    // tempt array to store entrie of the current board
    int sudoku_in[Sudoku::sudokuSize];

    // import a Sudoku board from infile
    for (int idx = 0; idx < Sudoku::sudokuSize; idx++){
        cin >> sudoku_in[idx];
    } // end inner for loop

    setMap(sudoku_in);
} // end function importSudoku
