#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool unique(string key_word)
{
    for (int i = 0; i < key_word.length() - 1; i++)
    {
        for (int j = i + 1; j < key_word.length(); j++)
        {
            if (key_word[i] == key_word[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    ifstream data{"data.txt"};
    string temp{};
    int sum{4};
    int start_index{0};
    string key_word{};
    data >> temp;
    for(int i = 0; i < temp.length(); i++)
    {
        key_word = temp.substr(start_index, 4);
        if(unique(key_word)) {
            cout << key_word << endl;
            cout << sum << endl;
            break;
        }
        start_index++;
        sum++;
    }
}