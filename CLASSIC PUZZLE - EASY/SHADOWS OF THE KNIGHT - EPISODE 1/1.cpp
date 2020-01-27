#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H;
    cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N;
    cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0;
    cin.ignore();

    int x = X0;
    int y = Y0;
    int xMin = 0;
    int yMin = 0;
    int xMax = W - 1;
    int yMax = H - 1;

    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir;
        cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        if (bombDir.find("U") != string::npos)
            yMax = y - 1;
        if (bombDir.find("D") != string::npos)
            yMin = y + 1;
        if (bombDir.find("L") != string::npos)
            xMax = x - 1;
        if (bombDir.find("R") != string::npos)
            xMin = x + 1;

        x = xMin + (xMax - xMin) / 2;
        y = yMin + (yMax - yMin) / 2;

        // the location of the next window Batman should jump to.
        cout << to_string(x) + " " + to_string(y) << endl;
    }
}