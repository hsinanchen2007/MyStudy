开始的时候知道这道题可以用栈去实现，但是一下子写不出来，反而是很容易写出了递归的解法，稍加分析就能写出栈解法了。***用栈去实现实质上是自己用栈去模拟递归的过程***。

***Talk is cheap. Show me the code.***

栈解法：
```
string decodeString(string s) {
    stack<int> numStack;
    stack<string> resStack;
    int num = 0;
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            res.push_back(s[i]);
        } else if (isdigit(s[i])) {
            num = num * 10 + s[i] - '0';
        } else if (s[i] == '[') {
            resStack.push(res);
            res = "";
            numStack.push(num);
            num = 0;
        } else {
            for (int j = 0; j < numStack.top(); j++) {
                resStack.top() += res;
            }
            numStack.pop();
            res = resStack.top();
            resStack.pop();
        }
    }
    return res;
}
```

递归解法（递归过程会重复扫描字符串，不推荐这种写法）：
```
string decodeString(string s) {
    int num = 0;
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            res.push_back(s[i]);
        } else if (isdigit(s[i])) {
            num = num * 10 + s[i] - '0';
        } else if (s[i] == '[') {
            int cnt = 0;
            i++;
            string innerS;
            while (s[i] != ']' || cnt != 0) {
                if (s[i] == '[') cnt++;
                else if (s[i] == ']') cnt--;
                innerS.push_back(s[i]);
                i++;
            }
            string innerRes = decodeString(innerS);
            while (num > 0) {
                res += innerRes;
                num--;
            }
        }
    }
    return res;
}
```



