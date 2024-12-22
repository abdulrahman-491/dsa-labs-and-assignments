#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdlib>
using namespace std;
int main() {
    stack <string> myStack;
    string S = "";
    int Q; //number of operations
    cin >> Q;
    string *ops = new string[Q+1]; // array of operations 
    for (int i = 0; i < Q + 1; i++)// filling operation array with the operation strings
        getline(cin, ops[i]);
    for (int i = 0; i < Q + 1; i++) // looping over the operations array
    {
        if (ops[i][0] == '1') // append
        {
            myStack.push(S);
            int j = 2;
            while (ops[i][j] != '\0')
            {
                S += ops[i][j];
                j++;
            }
        }
        else if (ops[i][0] == '2') // delete
        {
            myStack.push(S);
            int j = 2;
            string k = "";
            while (ops[i][j] != '\0')
            {
                k += ops[i][j];
                j++;
            }
            S = S.substr(0, S.length() - stoi(k));
        }
        else if (ops[i][0] == '3') // print
        {
            int j = 2;
            string k = "";
            while (ops[i][j] != '\0')
            {
                k += ops[i][j];
                j++;
            }
            cout << S[stoi(k) - 1] << "\n";
        }
        else if (ops[i][0] == '4') //undo
        {
            S = myStack.top();
            myStack.pop();
        }
    }
    delete [] ops;
    ops = nullptr;
    return 0;
}