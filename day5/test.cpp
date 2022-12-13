#include <queue>
#include <iostream>


using namespace std;


int main() {



    queue<char>test{};

    test.push('a');
    test.push('b');
    test.push('c');
    test.push('d');

    cout << test.back() << endl;
}