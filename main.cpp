#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <conio.h>

using namespace std;

vector<string> names {};

int RandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void GetNames() {
    string input;
    while (true)
        {
        cout << "Input name (or press ENTER to continue): ";
        getline(cin, input);
        if (input.empty())
            break;
        names.push_back(input);
        }
}

string PickName() {
    if (names.empty())
        return "no-one :(";
    int pickedIndex = RandomNumber(0, size(names) - 1);
    string pickedName = names[pickedIndex];
    names.erase(names.begin()+pickedIndex);
    return pickedName;
}

void AssignTeams() {
    string name1 = PickName();
    string name2 = PickName();
    cout << name1 << " pairs with " << name2 << endl;
}

int main() {
    srand(time(nullptr));
    GetNames();
    while (!names.empty())
        AssignTeams();
    cout << endl << "Press any key to close...";
    getch();
    return 0;
}