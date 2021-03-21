#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>


const int width = 5;
const int height = 5;
static const int _ = 0x00;
static const int X = 0x01;


class GameOfLife {
public:
int GOLgrid[height][width];

public:
GameOfLife(int matrix[height][width]);
GameOfLife();
int getLiveNeighbours(int cell_row, int cell_col);
int getNewCellState(int current_state, int live_neighbours);
void getNextGrid();
void printGrid();
};
