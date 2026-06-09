## 思路一：利用栈
**注意：对最小负数处理**
### 代码
```c++
class Solution {
public:
    int calculate(string s) {
        int size = s.size();
        long int num = 0, res = 0;
        stack<long> st;
        char op = '+';
        for (int i = 0; i < size; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '(') {
                int j = i, cnt = 0;
                for (; i < size; ++i) {
                    if (s[i] == '(') {
                        ++cnt;
                    }
                    if (s[i] == ')') {
                        --cnt;
                    }
                    if (cnt == 0) {  
                        num = calculate(s.substr(j+1, i-j-1));
                        break;
                    }                    
                }
                
            }
            if (ch < '0' && ch != ' ' || i == size - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*' || op == '/') {
                    long int tmp = (op == '*') ? st.top() * num : st.top() / num;
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
### 代码
```c++
class Solution {
public:
    int calculate(string s) {
        int size = s.size(), res = 0, curRes = 0;
        long int num = 0;//处理最小负数
        char op = '+';
        for (int i = 0; i < size; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '(') {
                int j = i, cnt = 0;
                for (; i < size; ++i) {
                    if (s[i] == '(') {
                        ++cnt;
                    }
                    if (s[i] == ')') {
                        --cnt;
                    }
                    if (cnt == 0) {                        
                        break;
                    }                    
                }
                num = calculate(s.substr(j+1, i-j-1));
            }
            if (ch < '0' && ch != ' ' || i == size - 1) {
                switch(op) {
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
