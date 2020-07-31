#include <iostream>
using namespace std;
int C = 0, n = 0, m = 0;
bool areFriends[10][10] = {false};

void printTaken(bool taken[10])
{
    cout << "taken : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << taken[i] << " ";
    }
    cout << endl;
}

int countPairings(bool taken[10])
{
    int firstFree = -1;
    for (int i = 0; i < n; i++)
    {
        if (taken[i] == false)
        {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1)
        return 1;

    int ret = 0;
    for (int pairWith = firstFree + 1; pairWith < n; ++pairWith)
    {
        if (taken[pairWith] == false && areFriends[firstFree][pairWith])
        {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main()
{
    cout << "Press." << endl;
    bool taken[10] = {0};
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> n >> m;
        for (int j = 0; j < m; j++)
        {
            int pair1 = 0, pair2 = 0;
            cin >> pair1 >> pair2;
            areFriends[pair1][pair2] = areFriends[pair2][pair1] = true;
        }
        int ret = countPairings(taken);
        cout << "answer : " << ret << endl;
        cout << "Ok" << endl;
    }
}
