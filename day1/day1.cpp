#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>



using namespace std;

int main() {

    ifstream elfFile{"data.txt"};
    string temp{};
    int sum{};
    vector<int>elfCal{};


    
    while(getline(elfFile, temp)) {
        
        if(temp.length() != 0) {
            sum = sum + stoi(temp);
            continue;
        }
        elfCal.push_back(sum);
        sum = 0;

    }

    std::sort(elfCal.begin(), elfCal.end());

    int n = elfCal.size();

    int topThree = elfCal[n-1] + elfCal[n-2] + elfCal[n-3];

    cout << topThree << endl;

    cout << elfCal[n-1];

}