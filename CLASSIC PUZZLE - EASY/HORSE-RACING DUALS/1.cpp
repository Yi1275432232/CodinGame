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
    int N;
    cin >> N;
    cin.ignore();

    vector<int> horses;
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi;
        horses.push_back(Pi);
        cin.ignore();
    }

    sort(begin(horses), end(horses));

    int minDifference = 99999999;
    for (int i = 0; i < N - 1; ++i) {
        int adjacentDifference = abs(horses.at(i) - horses.at(i + 1));
        if (minDifference > adjacentDifference)
            minDifference = adjacentDifference;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << minDifference << endl;
}