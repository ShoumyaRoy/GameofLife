#include <iostream>
#include<string>
#include <math.h>

using namespace std;

class GameOfLife {
    public:
	 static const int DEAD    = 0x00;
    public:
	 static const int LIVE    = 0x01;
	
	private:
	 void printGrid(int grid[5][5]) {
        for (int i = 0, e = 5 ; i < e ; i++) {
            for (int j = 0, f = 5 ; j < f ; j++) {
            	cout << to_string(grid[i][j]) << ",";
            } 
            cout << endl;
        }
    }
    
    private:
	 int getLiveNeighbours(int cell_row, int cell_col, int grid[5][5]) {
        int live_neighbours = 0;
        int row_end = min(5 , cell_row + 2);
        int col_end = min(5, cell_col + 2);
        for (int row = max(0, cell_row - 1) ; row < row_end ; row++) {
            
            for (int col = max(0, cell_col - 1) ; col < col_end ; col++) {
                
                if ((row != cell_row || col != cell_col) && grid[row][col] == LIVE) {
                    live_neighbours++;
                }
            }
        }
        return live_neighbours;
    }
    
    private:
	 int getNewCellState(int current_state, int live_neighbours) {

        int new_state = current_state;

        switch (current_state) {
        case LIVE:

            if (live_neighbours < 2) {
                new_state = DEAD;
            }

            if (live_neighbours == 2 || live_neighbours == 3) {
                new_state = LIVE;
            }

            if (live_neighbours > 3) {
                new_state = DEAD;
            }
            break;

        case DEAD:
            if (live_neighbours == 3) {
                new_state = LIVE;
            }
            break;

        default:
              cout << "Grid cell neither LIVE nor DEAD" << endl;
        }			
        return new_state;
    }
    
    public:
	 int getNextGrid(int grid[5][5]) {
        int buffer[5][5];
        for (int row = 0 ; row < 5 ; row++) {
	
            for (int col = 0 ; col < 5 ; col++) {
                buffer[row][col] = getNewCellState(grid[row][col], getLiveNeighbours(row, col, grid));
            }
        }   
        printGrid(buffer);
    }
    
	public:
	 void test() {
	 	int input;
		int grid1[5][5] = {{DEAD, DEAD, DEAD, DEAD, DEAD},
                          {DEAD, LIVE, LIVE, DEAD, DEAD},
                          {DEAD, LIVE, LIVE, DEAD, DEAD},
                          {DEAD, DEAD, DEAD, DEAD, DEAD},
                          {DEAD, DEAD, DEAD, DEAD, DEAD}};
        int grid2[5][5] = {{DEAD, LIVE, LIVE, DEAD, DEAD},
                     	  {LIVE, DEAD, LIVE, DEAD, DEAD},
                          {DEAD, LIVE, DEAD, DEAD, DEAD},
                          {DEAD, DEAD, DEAD, DEAD, DEAD},
                          {DEAD, DEAD, DEAD, DEAD, DEAD}};
        int grid3[5][5] = {{DEAD, DEAD, DEAD, DEAD, DEAD},
                          {LIVE, LIVE, LIVE, DEAD, DEAD},
                          {DEAD, DEAD, DEAD, DEAD, DEAD},
                          {DEAD, DEAD, DEAD, DEAD, DEAD},
                          {DEAD, DEAD, DEAD, DEAD, DEAD}};
        int grid4[5][5] = {{DEAD, DEAD, DEAD, DEAD, DEAD},
                          {DEAD, LIVE, LIVE, LIVE, DEAD},
                          {DEAD, DEAD, LIVE, LIVE, LIVE},
                          {DEAD, DEAD, DEAD, DEAD, DEAD},
                          {DEAD, DEAD, DEAD, DEAD, DEAD}};
                          
        cout << "Game of Life" << endl << endl;
        cout << "Input Options:" << endl;
        cout << "1" << endl;
        printGrid(grid1);
        cout << "2" << endl;
        printGrid(grid2);
        cout << "3" << endl;
        printGrid(grid3);
        cout << "4" << endl;
        printGrid(grid4);
        
        cout<< endl << "Enter input option number:" << endl;
        cin >> input;
        cout << endl;
        
  		switch (input){
  			case 1:
  				cout << "Output:"<<endl;
				getNextGrid(grid1);
			break;
            case 2:
            	cout << "Output:"<<endl;
				getNextGrid(grid2);
			break;
            case 3:
            	cout << "Output:"<<endl;
				getNextGrid(grid3);
			break;
        	case 4:
        		cout << "Output:"<<endl;
				getNextGrid(grid4);
			break;
			default: 
				cout << "Choose valid input option number." << endl; 
		}
    }
};

 int main() {
        GameOfLife gol;
        gol.test();
    }
