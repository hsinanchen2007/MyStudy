### 解题思路
看到很多转逆波兰式求解的，但是其实没有必要啊，直接操作数栈+操作符栈就可以了。要注意优先级的定义。
补充了两个特殊字符'#'和'$'，主要作用是简化代码，避免对边界情况的特殊处理。

### 代码

```cpp
unordered_map<char, int> order = {{'#', -1}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'$', 0}};

class Solution {
    string trim(string s) {
        string t;
        for (char c : s)
            if (c != ' ')
                t.push_back(c);
        return t;
    }
    
    int calc(int a, int b, char c) {
        switch(c) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                return a;
        }
    }
public:
    int calculate(string s) {
        s = trim(s);
        stack<int> val;
        stack<char> op;
        op.push('#');
        int num = 0;
        s += '$';
        for (char c : s) {
            int delta = c - '0';
            if (delta >= 0 && delta <= 9)
                num = num * 10 + delta;
            else {
                val.push(num);
                num = 0;
                while (order[op.top()] >= order[c]) {
                    int b = val.top();
                    val.pop();
                    int a = val.top();
                    val.pop();
                    val.push(calc(a, b, op.top()));
                    op.pop();
                }
                op.push(c);
            }
        }
        return val.top();
    }
};
```