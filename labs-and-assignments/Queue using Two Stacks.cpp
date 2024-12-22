#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<long long int> mainStack;
    stack<long long int> helperStack;
    void transferElements() 
    {
        while (!mainStack.empty()) 
        {
            helperStack.push(mainStack.top());
            mainStack.pop();
        }
    }

public:
    void enqueue(int value)
    {
        mainStack.push(value);
    }

    void dequeue()
    {
        if (helperStack.empty()) 
            transferElements();

        if (!helperStack.empty()) 
            helperStack.pop();
    }

    void front()
    {
        if (helperStack.empty()) 
            transferElements();

        if (!helperStack.empty()) 
            cout << helperStack.top() << "\n";
        else 
            cout << '\0' << "\n"; 
        
    }
};

int main() {

    Queue myQueue;
    int q; //number of queries
    cin >> q;
    string *ops = new string[q+1]; 

    for (int i = 0; i < q + 1; i++)
        getline(cin, ops[i]);
        
    for (int i = 0; i < q + 1; i++) 
    {
        if (ops[i][0] == '1') // enqueue
        {
            int j = 2;
            string k = "";
            while (ops[i][j] != '\0')
            {
                k += ops[i][j];
                j++;
            }
            myQueue.enqueue(stoi(k));
        }
        else if (ops[i][0] == '2') // dequeue
            myQueue.dequeue();

        else if (ops[i][0] == '3') // print front of the queue
            myQueue.front();

    } 
    return 0;
}
