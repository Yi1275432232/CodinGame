#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
    int result = 0;
    int minTemperature = 5526;
    int n; // the number of temperatures to analyse
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t;
        cin.ignore();
        if (abs(minTemperature) > abs(t) || (minTemperature < 0 && minTemperature == -t))
            minTemperature = t;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    if (n != 0)
        result = minTemperature;

    cout << result << endl;
}