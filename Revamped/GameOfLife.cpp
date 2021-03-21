#include "GameofLife.h"

using namespace std;

GameOfLife::GameOfLife(int matrix[height][width])
{
memcpy(GOLgrid, matrix, sizeof(GOLgrid));
}
GameOfLife::GameOfLife()
{
//memcpy(GOLgrid, 0, sizeof(GOLgrid));
}

int GameOfLife::getLiveNeighbours(int cell_row, int cell_col) {
int live_neighbours = 0;
int row_end = min(height, cell_row + 2);
int col_end = min(width, cell_col + 2);
for (int row = max(0, cell_row - 1); row < row_end; row++) {

for (int col = max(0, cell_col - 1); col < col_end; col++) {

if ((row != cell_row || col != cell_col) && GOLgrid[row][col] == X) {
live_neighbours++;
}
}
}
return live_neighbours;
}

int GameOfLife::getNewCellState(int current_state, int live_neighbours) {

int new_state = current_state;

switch (current_state) {
case X:

if (live_neighbours < 2) {
new_state = _;
}

if (live_neighbours == 2 || live_neighbours == 3) {
new_state = X;
}

if (live_neighbours > 3) {
new_state = _;
}
break;

case _:
if (live_neighbours == 3) {
new_state = X;
}
else
{
new_state = _;
}
break;

default:
cout << "Grid cell neither LIVE nor DEAD" << endl;
}
return new_state;
}

void GameOfLife::getNextGrid() {
int buffer[height][width];
for (int row = 0; row < height; row++) {
for (int col = 0; col < width; col++) {
buffer[row][col] = getNewCellState(GOLgrid[row][col], getLiveNeighbours(row, col));
}
}
//printGrid();
memcpy(GOLgrid, buffer, sizeof(GOLgrid));
}

void GameOfLife::printGrid() {
for (int i = 0; i < height; i++) {
for (int j = 0; j < width; j++) {
if (GOLgrid[i][j])
cout << " 1 ";
else
cout << " 0 ";
}
cout << endl;
}
}
