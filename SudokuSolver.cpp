#include <bits/stdc++.h>
using namespace std;
#define N 9
int grid[N][N];

bool inrow(int row, int num) {
  for(int col=0;col<N;++col) {
    if(grid[row][col] == num) {
      return true;
    }
  }
  return false;
}

bool incol(int col, int num) {
  for(int row=0;row<N;++row) {
    if(grid[row][col] == num) {
      return true;
    }
  }
  return false;
}

bool in3b3(int row, int col, int num) {
  for(int i=0;i<3;++i) {
    for(int j=0;j<3;++j) {
      if(grid[row+i][col+j]==num)
        return true;
    }
  }
  return false;
}

// finds empty place in the grid
bool EmptyPlace(int &row, int &col) {
  for(row=0;row<N;++row) {
    for(col=0;col<N;++col) {
      if(!grid[row][col])
        return true;
    }
  }
  return false;
}

// checks if number is already present in row,col,box
bool isValidPlace(int row, int col, int num) {
  return !inrow(row,num) && !incol(col,num) && !in3b3(row-row%3, col-col%3, num);
}
//
bool sudoku_solve() {
  int row, col;
  if(!EmptyPlace(row, col))
    return true;

  for(int num=1;num<=9;++num) {
    if(isValidPlace(row, col, num)) {
      grid[row][col] = num;
      if(sudoku_solve()) 
        return true;
      grid[row][col] = 0;
    }
  }
  return false;
}
// to print 
void printsudoku() {
  for(int row=0;row<N;++row) {
    for(int col=0;col<N;++col) {
      if(col == 3 || col == 6)
        printf(" | ");
      printf("%d ",grid[row][col]);
    }
    if(row == 2 || row == 5) {
      printf("\n");
      for(int i=0;i<N;++i) {
        printf("---");
      }
    }
    printf("\n");
  }
}

// main function
signed main() {

  for(int i=0;i<9;++i) {
    for(int j=0;j<9;++j) {
      scanf("%d",&grid[i][j]);
    }
  }
  if(sudoku_solve()) {
    printf("Solution exists\n");
    printsudoku();
    return 0;
  }

  printf("No solution exists for given sudoku!!\n");
  return 0;
}
