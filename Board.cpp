/*
Author: Emmy Veselinov
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 3 Game 1024

Task A: contains default constructor, parameterized constructors, deconstructor, 
and a print method which prints the panel in a tabular format.

Task B: contains the functions noAdjacentSameValue and selectRandomCell.

Task C: pressUp() pressDown() pressLeft() pressRight()
*/


#include <iostream>
#include <cstdlib>
#include <iomanip> //setw
#include <vector>
#include "Board.hpp"

//3 different constructors based on diff sizes given

/*
//default constructor
Board::Board(){
    max = 0;
    target = 32;
    numRows = 3;
    numCols = 3;

    //initalize panel as a 2d array of numRows rows and numCols
    panel = new int* [numRows]; //dynamic array of with size numRows of pointers that point to an int

    //create a dynamic 2 dimensional array (a pointer to a pointer)
    for (int i = 0; i < numRows; i++){
        panel[i] = new int[numCols]; //ith pointer pointing to a dynamic arr of int values
    }


}

Board::Board(int m){
    max = 0;
    target = 32;
    numRows = m;
    if (m >= 1){
        numCols = m;
    }
    else {
        numRows = 3;
        numCols = 3;
    }

    //set panel to a 2d array with numRows rows and numCols cols 
    panel = new int* [numRows];
    for (int i = 0; i < numRows; i++){
        panel[i] = new int[numCols];
    }



}

Board::Board(int m, int n){
    max = 0;
    target = 32;
    if (m && n >= 1){
        numRows = m;
        numCols = n;
    }
    else {
        numRows = 3;
        numCols = 3;

    }

    panel = new int* [numRows];
    for (int i = 0; i < numRows; i++){
        panel[i] = new int[numCols];
    }



}




//deconstructor (release the memory space pointed by panel & handle dangling pointer)
Board::~Board(){

    for (int i = 0; i < numRows; i++){
        delete[] panel[i];
        panel[i] = nullptr;
    }

    delete[] panel;
    panel = nullptr;

}

*/

void Board::print() const{
    if (numRows != 0 && numCols != 0){ // if the columns and rows are 0, don't print out anything

        for (int i = 0; i < numRows; i++){
            std::cout << "+";
            
            for (int j = 0; j < numCols; j++){
                std::cout << "----+";
            }
            std::cout << "\n";

            for (int c = 0; c < numCols; c++){
                if (c == 0){
                    std::cout << "|";
                }
                if (panel[i][c] != 0){
                    std::cout << std::setw(4) << panel[i][c] << "|";
                    //std::cout << std::setw(3) << "|";
                }

                else {
                    std::cout << std::setw(5) << "|";
                }
            }
            std::cout << "\n";
            
        }   

        std::cout << "+";
        for (int i = 0; i < numCols; i++){
            std::cout << "----+";
        }
    }
    std::cout << "\n";
}

//only selectRandomCell can call this method

/*
bool Board::noAdjacentSameValue() const{
    //horizontal direction (check pairs in every row)
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols - 1; j++){
            //first pair col indices 0 & 1, then 1 & 2, up to numCols - 2 & numCols - 1
            if (panel[i][j] == panel[i][j+1]){
                return false; //game is not over
            }
        }
    }

    //vertical direction
    for (int j = 0; j < numCols; j++){
        for (int i = 0; i < numRows - 1; i++){
            if (panel[i][j] == panel[i+1][j]){
                return false;
            }
        }
    }


    //no false return in either nested for loops means that there are no adj value pairs; game is over
    //if (max < target){
    //    return true;
    //}
    return true;

}

void Board::selectRandomCell(int& row, int& col){
    int tally = 0;
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            if (panel[i][j] == 0){
                tally++;
            }
        }
    }

    if (tally == 0 && noAdjacentSameValue() == true && max < target){
        std::cout << "Game over. Try again." << std::endl;
        std::exit(0); //exit the program
    }

    int* labelEmptyCells = new int[tally]; //array with the num of empty cells
    int emptyCounter = 0;
    
    if (tally > 0){ //at least one empty cell
       
        for (int i = 0; i < numRows; i++){ //first row (move left to right) then second row..etc
            for (int j = 0; j < numCols; j++){
                if (panel[i][j] == 0){
                    labelEmptyCells[emptyCounter] = (i * numCols) + j; //the current row index * the numCols + the current col index
                    emptyCounter++;
                }

            }
        }
    }

    //select random element from the above array
    //convert it back into the original row and column 
    //set the corresponding cell to store the value 1

    int randomIndex, randomElement, rowIndex, colIndex;
    
    randomIndex = rand() % tally; //falls in [0,tally-1]        
    randomElement = labelEmptyCells[randomIndex];

    //note: to get the row index: divide index by numCols // to get the col index: index mod numCols
    rowIndex = randomElement/numCols;
    colIndex = randomElement % numCols;
    panel[rowIndex][colIndex] = 1;

    print(); 

    
    if (noAdjacentSameValue() == true && max < target){
        std::cout << "Game over. Try again." << std::endl;
        std::exit(0); //exit the program
    }


    delete[] labelEmptyCells;
    labelEmptyCells = nullptr;
}

*/

void Board::pressUp(){
    
    //for each column
    for (int i = 0; i < numCols; i++){
        std::vector<int> nonZeros; //save non-zeros to a vec of integers
        for (int j = 0; j < numRows; j++){ // from TOP TO BOTTOM
            if (panel[j][i] != 0){
                nonZeros.push_back(panel[j][i]);
            }
            
        }

        int curr = 0; //starting row index for the nonZeros vector
        
        while (curr < nonZeros.size()){ //while curr is less than the size, execute statements
        //every item in the vector gets processed

            //merge curr and downstairs neighbor
            if (curr + 1 < nonZeros.size() && (nonZeros[curr] == nonZeros[curr + 1])){
                nonZeros[curr] = nonZeros[curr] + nonZeros[curr + 1];
                nonZeros[curr + 1] = 0;
                curr = curr + 2; //increase curr by 2
                //update max if necessary
                if (nonZeros[curr] > max){
                    max = nonZeros[curr];
                }

            }

            else {
                curr++;
            }

        }

            

        //copy all the non-zeros in the vector to the first column TOP TO BOTTOM
        int row = 0; // the rows in the column we are in
        for (curr = 0; curr < nonZeros.size(); curr++){
            if (nonZeros[curr] != 0){
                panel[row][i] = nonZeros[curr];
                row++;

            }
        }

        
        //pad the remaining row values to be 0 (as they were not in the nonZeros vector)
        for (int k = row; k < numRows; k++){
            panel[k][i] = 0;
        }
        
    
       
    }
    int r;
    int c;

    selectRandomCell(r, c);

}


void Board::pressDown(){

    //for each column
    //get all non-zeros of column to the nonZeros vector
    for (int i = 0; i < numCols; i++){
        std::vector<int> nonZeros; //save non-zeros to a vec of integers
        for (int j = numRows - 1; j >= 0; j--){ // from BOTTOM TO TOP
            if (panel[j][i] != 0){
                nonZeros.push_back(panel[j][i]);
            }
            
        }

        int curr = nonZeros.size() - 1; //starting row index at the last element of the nonZeros vector
        bool didMerge = false; //when there are no adjacent same values in the vector, didMerge is false and changed to true otherwise
        
        //purpose: merge adjacent same value elements of nonZeros
        while (curr > 0){ //while curr (current element in the vector) is less than the size, execute statements
        //every item in the vector gets processed

            //merge curr and upstairs neighbor
            if (curr - 1 < nonZeros.size() && (nonZeros[curr] == nonZeros[curr - 1])){
                nonZeros[curr] = nonZeros[curr] + nonZeros[curr - 1];
                nonZeros[curr - 1] = 0;
                didMerge = true;
                if (nonZeros[curr - 2] != 0 && (curr - 2 == 0)){ // for cases where its 4 0 4, so the 0 can be swapped with the first element
                    nonZeros[curr - 1] = nonZeros[curr - 2];
                    nonZeros[curr - 2] = 0;
                    
                }
            
                //update max if necessary
                if (nonZeros[curr] > max){
                    max = nonZeros[curr];
                }
                curr = curr - 2; //decrease curr by 2

            }

            else {
                curr--;
            }

        }

            

        //copy all the non-zeros in the vector to the first column BOTTOM TO TOP
        
        int row = nonZeros.size() - 1; // the rows in the column we are in
        if (didMerge == false){
            row = 0;
        }
        for (curr = nonZeros.size() - 1; curr >= 0; curr--){
            if (didMerge == false){
                panel[row][i] = nonZeros[curr];
                row++;

            }
            else if (didMerge == true){
                if (nonZeros[curr] != 0){
                    
                    panel[row][i] = nonZeros[curr];
                    row--;

                }
            }
            
        }

        
        //pad the remaining row values to be 0 (as they were not in the nonZeros vector)
        if (row != nonZeros.size()){ //if row is == to the size of the nonZeros vector, all the values are already added to the panel (no 0's)
            for (int k = 0; k <= row; k++){
                panel[k][i] = 0;
            }
        }
        
        
       
    }
    int r;
    int c;

    selectRandomCell(r, c);

}

void Board::pressLeft(){
    //for each row (going horizontally)
    for (int i = 0; i < numRows; i++){
        std::vector<int> nonZeros; //save non-zeros to a vec of integers
        for (int j = 0; j < numCols; j++){ 
            if (panel[i][j] != 0){
                nonZeros.push_back(panel[i][j]);
            }
            
        }

        int curr = 0; //starting row index for the nonZeros vector
        
        while (curr < nonZeros.size()){ //while curr is less than the size, execute statements
        //every item in the vector gets processed

            //merge curr and downstairs neighbor
            if (curr + 1 < nonZeros.size() && (nonZeros[curr] == nonZeros[curr + 1])){
                nonZeros[curr] = nonZeros[curr] + nonZeros[curr + 1];
                nonZeros[curr + 1] = 0;
                curr = curr + 2; //increase curr by 2
                //update max if necessary
                if (nonZeros[curr] > max){
                    max = nonZeros[curr];
                }

            }

            else {
                curr++;
            }

        }

            

        //copy all the non-zeros in the vector to the first row 
        int col = 0; // the cols in the row we are in
        for (curr = 0; curr < nonZeros.size(); curr++){
            if (nonZeros[curr] != 0){
                panel[i][col] = nonZeros[curr];
                col++;

            }
        }

        
        //pad the remaining col values to be 0 (as they were not in the nonZeros vector)
        for (int k = col; k < numCols; k++){
            panel[i][k] = 0;
        }
        
    
       
    }
    int r;
    int c;

    selectRandomCell(r, c);

}




void Board::pressRight(){

    //for each row
    //get all non-zeros of row to nonZeros 
    for (int i = 0; i < numRows; i++){
        std::vector<int> nonZeros; //save non-zeros to a vec of integers
        for (int j = 0; j < numCols; j++){ // from BOTTOM TO TOP
            if (panel[i][j] != 0){
                nonZeros.push_back(panel[i][j]);
            }
            
        }

        int curr = nonZeros.size() - 1; //starting col index at the last element of the nonZeros vector
        bool didMerge = false; //when there are no adjacent same values in the vector, didMerge is false and changed to true otherwise
        
        //purpose: merge adjacent same value elements of nonZeros
        while (curr > 0){ //while curr (current element in the vector) is less than the size, execute statements
        //every item in the vector gets processed

            //merge curr and upstairs neighbor
            if (curr - 1 < nonZeros.size() && (nonZeros[curr] == nonZeros[curr - 1])){
                nonZeros[curr] = nonZeros[curr] + nonZeros[curr - 1];
                nonZeros[curr - 1] = 0;
                didMerge = true;
                if (nonZeros[curr - 2] != 0 && (curr - 2 == 0)){ 
                    nonZeros[curr - 1] = nonZeros[curr - 2];
                    nonZeros[curr - 2] = 0;
                    
                }
            
                //update max if necessary
                if (nonZeros[curr] > max){
                    max = nonZeros[curr];
                }
                curr = curr - 2; //decrease curr by 2

            }

            else {
                curr--;
            }

        }

            

        //copy all the non-zeros in the vector to the first col 
        
        int col = nonZeros.size() - 1; // the col in the column we are in

        for (curr = nonZeros.size() - 1; curr >= 0; curr--){
            if (didMerge == false){

                panel[i][col] = nonZeros[curr];
                col--;

            }
            else if (didMerge == true){
                if (nonZeros[curr] != 0){
                    
                    panel[i][col] = nonZeros[curr];
                    col--;

                }
            }
            
        }

        
        //pad the remaining col values to be 0 (as they were not in the nonZeros vector)
        if (col != nonZeros.size()){ //if col is == to the size of the nonZeros vector, all the values are already added to the panel (no 0's)
            for (int k = 0; k <= col; k++){
                panel[i][k] = 0;
            }
        }
        
        
       
    }
    int r;
    int c;

    selectRandomCell(r, c);

    
}











