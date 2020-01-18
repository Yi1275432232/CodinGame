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
    int L;
    cin >> L;
    cin.ignore();
    int H;
    cin >> H;
    cin.ignore();
    string T;
    getline(cin, T);
    transform(T.begin(), T.end(), T.begin(), ::toupper);

    int A = (int)'A';
    int Z = (int)'Z';

    string answer = "";

    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);

        for (int j = 0; j < T.size(); j++) {
            if (T[j] >= A && T[j] <= Z) {
                int index = (int)T[j] - A;
                answer += ROW.substr(index * L, L);
            } else {
                answer += ROW.substr(26 * L, L);
            }
        }
        answer += "\n";
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << answer << endl;
}