#include <string>
#include <stack>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>
#include <deque>

using namespace std;

void create_stacks(ifstream &crates, vector<stack<char>> &containers)
{
    string temp{};
    int stack_index{0};
    stack<char> stack_1{};
    stack<char> stack_2{};
    stack<char> stack_3{};
    stack<char> stack_4{};
    stack<char> stack_5{};
    stack<char> stack_6{};
    stack<char> stack_7{};
    stack<char> stack_8{};
    stack<char> stack_9{};

    containers.push_back(stack_1);
    containers.push_back(stack_2);
    containers.push_back(stack_3);
    containers.push_back(stack_4);
    containers.push_back(stack_5);
    containers.push_back(stack_6);
    containers.push_back(stack_7);
    containers.push_back(stack_8);
    containers.push_back(stack_9);

    while (getline(crates, temp))
    {
        for (int i = 0; i < temp.length(); i++)
        {
            containers[stack_index].push(temp.at(i));
        }
        stack_index++;
    }
}

void find_words(string &temp, int &amount, int &sender, int &reciever)
{
    vector<string> words{};
    string vec_push{};
    stringstream ss{temp};

    while (ss >> vec_push)
    {
        words.push_back(vec_push);
    }

    amount = stoi(words[1]);
    sender = stoi(words[3]);
    reciever = stoi(words[5]);
    sender-=1;
    reciever-=1;
}

void move_crates(ifstream &data, vector<stack<char>> &containers)
{
    string temp{};
    int amount{};
    int sender{};
    int reciever{};
    char crate{};
    deque<char> crane{};
    while (getline(data, temp))
    {
        find_words(temp, amount, sender, reciever);
        for (int i = 0; i < amount; i++)
        {
            crate = containers[sender].top();
            crane.push_front(crate);
            containers[sender].pop(); 
        }
        for (int i = 0; i < amount; i++) {
            crate = crane.front();
            crane.pop_front();
            containers[reciever].push(crate);
        }
    }

}

int main()
{

    ifstream data{"data.txt"};
    ifstream crates{"crates.txt"};
    vector<stack<char>> containers{};

    create_stacks(crates, containers);

    move_crates(data, containers);

    int stack_index{9};

    for(int i = 0; i < stack_index; i++) {
        cout << containers[i].top();
    }
    cout << endl;
}