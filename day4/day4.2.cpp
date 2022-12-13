#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

int main()
{

    FILE *data = fopen("data.txt", "r");
    int a1{}, a2{}, b1{}, b2{};
    int sum{0};
    std::cout << "OPEN" << endl;

    while (fscanf(data, "%d-%d, %d-%d", &a1, &a2, &b1, &b2) == 4)
    {
        std::cout << a1 << "-";
        std::cout << a2 << ",";
        std::cout << b1 << "-";
        std::cout << b2 << endl;

        if ((a1 <= b1 && b1 <= a2) || (b1 <= a1 && a1 <= b2))

        {
            std::cout << "YES" << endl;
            sum += 1;
            continue;
        }
        else
        {
            std::cout << "NO" << endl;
            continue;
        }
    }
    std::cout << sum << endl;
}
