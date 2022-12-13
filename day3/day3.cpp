#include <fstream>
#include <string>
#include <iostream>

using namespace std;

char check_shared(const string first, const string second, const string third)
{

    for (auto frst : first)
    {
        for (auto scnd : second)
        {
            for (auto thrd : third)
            {
                if (frst == scnd && frst == thrd && scnd == thrd)
                {
                    return frst;
                }
            }
        }
    }
    return 0;
}

int calc_priority(const string first, const string second, const string third)
{

    /* string first_compartment = temp.substr(0, temp.size() / 2);
     string second_compartment = temp.substr(temp.size() / 2, temp.size() / 2);
    */

    char shared_item = check_shared(first, second, third);
    return isupper(shared_item) ? (shared_item - 'A') + 27 : (shared_item - 'a') + 1;
}

int main()
{

    ifstream data("data.txt");
    string first_elf{}, second_elf{}, third_elf{};

    int priority_sum{};
    while (data >> first_elf && data >> second_elf && data >> third_elf)
    {
        priority_sum += calc_priority(first_elf, second_elf, third_elf);
    }

    cout << priority_sum << endl;
}
