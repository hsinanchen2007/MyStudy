***Talk is cheap. Show me the code.***
```
string reverseParentheses(string s) {
    string res;
    stack<string> stk;
    for (char &c : s) {
        if (c == '(') {
            stk.push(res);
            res = "";
        } else if (c == ')') {
            reverse(res.begin(), res.end());
            res = stk.top() + res;
            stk.pop();
        } else {
            res.push_back(c);
        }
    }
    return res;
}
```
![1113.png](https://pic.leetcode-cn.com/bb4b5807ffaf9b30f7453a5b69e7d6ab5038610ee8f5672f1ac6dba8853a71dd-1113.png)

