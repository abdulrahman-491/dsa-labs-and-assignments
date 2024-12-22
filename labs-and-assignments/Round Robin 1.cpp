#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    char pName;
    int n, q, pTime;
    queue <char> names;
    queue <int> burstTimes;
    cin >> n;
    cin >> q;
    
    for (int i = 1; i <= n; i++) // filling the processes queue and burst time queue
    {
        cin >> pName;
        cin >> pTime;
        names.push(pName);
        burstTimes.push(pTime);
    }
    
    while(!names.empty() && !burstTimes.empty())
    {
        pName = names.front();
        pTime = burstTimes.front();
        names.pop();
        burstTimes.pop();
        cout << pName;
        
        if (pTime > q)
        {
            names.push(pName);
            burstTimes.push(pTime - q);
        }    
    }

    return 0;
}