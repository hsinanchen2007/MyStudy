## 思路一
if 当前遇到操作符，则根据前一个操作符类型进行操作：
- if '+': 当前数放入数字栈中
- else if '-': 当前数负数放入栈中
- else if '*' 或 '/': 需要从栈中弹出一个数，然后和当前数进行 '\*' 或 '/' 操作，再将结果放入栈中。

最后需要保存当前操作符并重置当前数值为 0 。
### 代码
```c++
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int size = s.size();
        int res = 0, num = 0;
        char op = '+';
        for (int i = 0; i < size; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            if (ch < '0' && ch != ' ' || i == size - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*' || op == '/') {
                    int tmp = (op == '*') ? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = ch;
                num = 0;                
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
```

## 思路二
通过curRes保存部分结果值。
**注意：判断是否到达最后一个字符**
### 代码
```c++
class Solution {
public:
    int calculate(string s) {
        int size = s.size();
        int res = 0, num = 0, curRes = 0;
        char op = '+';
        for (int i = 0; i < size; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            if (ch < '0' && ch != ' ' || i == size - 1) {//如果到最后一个字符，则直接根据前一个操作符进行运算
                switch (op) {
                    case '+':
                        curRes += num;break;
                    case '-':
                        curRes -= num;break;
                    case '*':
                        curRes *= num;break;
                    case '/':
                        curRes /= num;break;                    
                }
                if (ch == '+' || ch == '-' || i == size - 1) {
                    res += curRes;
                    curRes = 0;
                }
                op = ch;
                num = 0;
            }
        }
        return res;
    }
};
```
