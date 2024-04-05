#include <iostream>
using namespace std;


void printGrid(int grid[9][9])
{
    for (int row = 0; row < 9; row++) 
    {
        for (int col = 0; col < 9; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}


bool isSafe(int grid[9][9], int row, int col, int num) 
{
    // Check if the number is already present in the row
    for (int i = 0; i < 9; i++) 
    {
        if (grid[row][i] == num)
            return false;
    }
    
    // Check if the number is already present in the column
    for (int i = 0; i < 9; i++) 
    {
        if (grid[i][col] == num)
            return false;
    }
    
    // Check if the number is already present in the 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    
    return true;
}


bool solveSudoku(int grid[9][9]) 
{
    int row, col;
    

    bool isEmpty = true;
    for (row = 0; row < 9; row++) 
    {
        for (col = 0; col < 9; col++) 
        {
            if (grid[row][col] == 0) 
            {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) 
        {
            break;
        }
    }
    
    
    if (isEmpty)
        return true;
    
   
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            
           
            if (solveSudoku(grid))
                return true;
            
          
            grid[row][col] = 0;
        }
    }
    
   
    return false;
}

int main() {
    int grid[9][9];
    
    cout << "Enter the Sudoku puzzle (use 0 for empty cells):" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
        }
    }
    
    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout << "No solution exists!" << endl;
    
    return 0;
}
