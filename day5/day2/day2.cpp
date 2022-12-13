#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    // A = Rock, B = Paper, C = Scissor, Y = Paper, X = Rock, Z = Scissor
    ifstream dataFile{"data.txt"};
    string temp{};
    int sum{};

    //X = Lose, Y = Draw, Z = Win
    while (getline(dataFile, temp))
    {
        if (temp == "A Y")
        {
            sum += 4;
        }
        else if (temp == "A X")
        {
            sum += 3;
        }
        else if (temp == "A Z")
        {
            sum += 8;
        }
        else if (temp == "B Y")
        {
            sum += 5;
        }
        else if (temp == "B X")
        {
            sum += 1;
        }
        else if (temp == "B Z")
        {
            sum += 9;
        }
        else if (temp == "C Y")
        {
            sum += 6;
        }
        else if (temp == "C X")
        {
            sum += 2;
        }
        else if (temp == "C Z")
        {
            sum += 7;
        }
        continue;
    }

    cout << sum << endl;
}