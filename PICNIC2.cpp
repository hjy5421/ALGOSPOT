#include <iostream>
using namespace std;
int n = 0, m = 0;
bool areFreinds[10][10];

int countPairings(bool taken[10])
{
    int firstFree = -1;
    for (int i = 0; i < n; i++)
    {
        if (taken[i] == false)
            firstFree = i;
    }

    if (firstFree == -1)
        return 1;

    int ans = 0;
    for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
    {
        if (taken[pairWith] == false && areFreinds[firstFree][pairWith])
        {
            taken[firstFree] = taken[pairWith] = true;
            ans += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ans;
}