#include"game_of_life.h"
#include<ctime>
#include<cmath>
using namespace std;

bool game_of_life::random_value()
{
    int randomNumber = rand() % 4;
    if (randomNumber == 0) return true;
    else if (randomNumber == 1) return false;
    else if (randomNumber == 2) return false;
    else if (randomNumber == 3) return false;
}

bool game_of_life::cell_taken(int i, int j)
{
    if (_generation[i][j] == true) return true;
    else return false;
}

game_of_life::game_of_life()
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            _generation[i][j] = random_value();
        }
    }
}

int game_of_life::count_adjacent(int x, int y)
{
    int counter = 0;
    for (int i = -1; i < 2; ++i)
    {
        for (int j = -1; j < 2; ++j)
        {
            if (i == 0 && j == 0) continue;
            int neighbourX = x + i;
            int neighbourY = y + j;
            if (0 <= neighbourX && neighbourX < COLS && 0 <= neighbourY && neighbourY < ROWS && cell_taken(neighbourX, neighbourY))
            {
                counter++;
            }
        }
    }
    return counter;
}

void game_of_life::next_generation()
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            int numNeighbours = count_adjacent(i, j);
            if (cell_taken(i, j))
            {
                if (numNeighbours < 2 || 3 < numNeighbours) _next_generation[i][j] = false;
                else if (numNeighbours == 2 || numNeighbours == 3) _next_generation[i][j] = true;
            }
        }
    }
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            _generation[i][j] = _next_generation[i][j];
        }
    }
}

void game_of_life::draw()
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
           if (cell_taken(i, j)) cout << '*';
           else cout << '-';
        }
        cout << endl;
    }
}
