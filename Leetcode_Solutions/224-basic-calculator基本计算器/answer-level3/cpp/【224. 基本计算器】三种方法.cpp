## 思路一
**注意**
- 处理数字可能是多位，如：23
- 空格不做任何处理，所以最后是else if
### 代码
```c++
class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, size = s.size();
        stack<int> st;
        for (int i = 0; i < size; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                int num = 0;
                while (i < size && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                res += sign * num;
                --i;
            } else if (ch == '+') {
                sign = 1;
            } else if (ch == '-') {
                sign = -1;
            } else if (ch == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (ch == ')'){
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        return res;
    }
};
```

## 思路二
和上面的区别是单个读取数字字符。
### 代码
```c++
class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, num = 0, size = s.size();
        stack<int> st;
        for (int i = 0; i < size; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (s[i] - '0');                
            } else if (ch == '+' || ch == '-') {
                res += num * sign;
                num = 0;
                sign = (ch == '+') ? 1 : -1;
            } else if (ch == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (ch == ')'){
                res += num * sign;
                num = 0;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        res += num * sign;
        return res;
    }
};
```

## 思路三：递归
将括号内部表达式通过递归计算。
### 代码
```c++
class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, num = 0, size = s.size();
        stack<int> st;
        for (int i = 0; i < size; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '(') {
                int j = i, cnt = 0;
                while (i < size) {
                    if (s[i] == '(') {
                        ++cnt;
                    }
                    if (s[i] == ')') {
                        --cnt;
                    }
                    if (cnt == 0) {
                        num = calculate(s.substr(j+1, i-j-1));//递归计算括号内表达式值
                        break;
                    }
                    ++i;
                }
            }
            if (ch == '+' || ch == '-' || i == size-1) {
                res += num * sign;
                num = 0;
                sign = (ch == '+') ? 1 : -1;                
            }            
        }
        return res;
    }
};
```

