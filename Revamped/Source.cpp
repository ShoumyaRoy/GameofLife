#include "GameofLife.h"

using namespace std;

const int num_options = 4;
int inputs[num_options][height][width] = { { { _, _, _, _, _ },{ _, X, X, _, _ },{ _, X, X, _, _ },{ _, _, _, _, _ },{ _, _, _, _, _ } },
{ { _, X, X, _, _ },{ X, _, X, _, _ },{ _, X, _, _, _ },{ _, _, _, _, _ },{ _, _, _, _, _ } },
{ { _, _, _, _, _ },{ X, X, X, _, _ },{ _, _, _, _, _ },{ _, _, _, _, _ },{ _, _, _, _, _ } },
{ { _, _, _, _, _ },{ _, X, X, X, _ },{ _, _, X, X, X },{ _, _, _, _, _ },{ _, _, _, _, _ } } };

void printInput(int index)
{
for (int i = 0; i < height; i++) {
for (int j = 0; j < width; j++) {
if (inputs[index - 1][i][j])
cout << " 1 ";
else
cout << " 0 ";
}
cout << endl;
}
}

int main()
{

int input =1;

cout << "Game of Life" << endl << endl;
cout << "Input Options:" << endl;
for(int options = 1; options <= num_options; options++)
{
cout << options << endl;
printInput(options);
}

cout << endl << "Enter input option number:" << endl;
cin >> input;
cout << endl;
GameOfLife gol;
gol = GameOfLife(inputs[input - 1]);

while (input >= 0 && input <= num_options)
{
if (input)
{
gol = GameOfLife(inputs[input - 1]);
}
gol.getNextGrid();
gol.printGrid();

cout << endl << "Enter input option number:" << endl;
cin >> input;
cout << endl;
}
}

