#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
    string MESSAGE;
    getline(cin, MESSAGE);
    string message = "";
    string temp = "";

    for (int i = 0; i < MESSAGE.size(); ++i) {
        bitset<7> bs(MESSAGE[i]);
        message += bs.to_string();
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    string answer = "";
    char previous = message[0];
    int count = 0;

    for (int i = 0; i < message.size(); ++i) {
        char c = message[i];

        if (c == previous) {
            ++count;
        } else {
            if (previous == '0')
                answer += "00 ";
            else
                answer += "0 ";

            for (int j = 0; j < count; ++j)
                answer += "0";

            answer += " ";
            count = 1;
        }

        previous = message[i];
    }

    if (previous == '0')
        answer += "00 ";
    else
        answer += "0 ";

    for (int j = 0; j < count; ++j)
        answer += "0";

    cout << answer << endl;
}