string isBalanced(string s) {
    
    stack <char> myStack;
    myStack.push('N');  
    myStack.push(s[0]);

    for (unsigned int i = 1; i < s.length(); i++) {
        if (
            ( myStack.top() == '[' && s[i] == ']' ) || 
            ( myStack.top() == '{' && s[i] == '}' ) ||
            ( myStack.top() == '(' && s[i] == ')' ) 
            )
        {
            myStack.pop();
        }
        else
            myStack.push(s[i]);
    }
    
    if (myStack.top() == 'N')
        return "YES";
    return "NO";
}