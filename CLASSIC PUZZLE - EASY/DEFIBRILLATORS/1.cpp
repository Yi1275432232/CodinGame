#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<string> split(string str, string pattern) {
    vector<string> parts;
    string::size_type pos = string::npos;

    for (int i = 0; i < str.size(); ++i) {
        pos = str.find(pattern, i);

        if (pos != string::npos) {
            string s = "";
            s = str.substr(i, pos - i);
            parts.push_back(s);
            i = pos + pattern.size() - 1;
        } else {
            string s = str.substr(i, str.size() - 1);
            parts.push_back(s);
            break;
        }
    }

    return parts;
}

double calculateDistance(double uLongitude, double uLatitude, double dLongitude, double dLatitude) {
    double x = (dLongitude - uLongitude) * cos((uLatitude + dLatitude) / 2);
    double y = dLatitude - uLatitude;
    double d = sqrt(pow(x, 2) + pow(y, 2)) * 6371;
    return d;
}

int main() {
    string LON;
    cin >> LON;
    cin.ignore();
    replace(LON.begin(), LON.end(), ',', '.');
    double uLongitude = atof(LON.c_str());
    uLongitude = uLongitude * 180 / M_PI;

    string LAT;
    cin >> LAT;
    cin.ignore();
    replace(LAT.begin(), LAT.end(), ',', '.');
    double uLatitude = atof(LAT.c_str());
    uLatitude = uLatitude * 180 / M_PI;

    int N;
    cin >> N;
    cin.ignore();

    map<double, string> distanceNameMap;

    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        vector<string> defibrillator = split(DEFIB, ";");

        string name = defibrillator.at(1);

        replace(defibrillator.at(4).begin(), defibrillator.at(4).end(), ',', '.');
        double dLongitude = atof(defibrillator.at(4).c_str());
        dLongitude = dLongitude * 180 / M_PI;

        replace(defibrillator.at(5).begin(), defibrillator.at(5).end(), ',', '.');
        double dLatitude = atof(defibrillator.at(5).c_str());
        dLatitude = dLatitude * 180 / M_PI;

        double distance = calculateDistance(uLongitude, uLatitude, dLongitude, dLatitude);
        distanceNameMap[distance] = name;
    }

    double minDistance = 9999999999;
    string minName;
    map<double, string>::iterator iterator;
    for (iterator = distanceNameMap.begin(); iterator != distanceNameMap.end(); ++iterator) {
        if (minDistance > iterator->first) {
            minDistance = iterator->first;
            minName = iterator->second;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << minName << endl;
}