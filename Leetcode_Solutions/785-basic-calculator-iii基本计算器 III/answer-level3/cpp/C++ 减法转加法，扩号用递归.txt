参考227题的解法，只需要多加一个条件，遇到左括号开始找匹配的右括号位置，然后中间的字符串递归计算，返回值是当前值cur。

可以对比一下两道题的代码：

本题代码：

```
class Solution {
public:
    int calculate(string s) {
        stack<int> ss;
        char sign = '+';
        long cur = 0;
        for (int i = 0; i < s.size() + 1; ++i) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * 10 + (s[i] - '0');
            } else if (s[i] == '(') {
                int k = i + 1, l = 1, r = 0;
                for (; k < s.size(); ++k) {
                    if (s[k] == '(') {
                        l++;
                    } else if (s[k] == ')') {
                        r++;
                        if (r == l) break;
                    }
                }
                cur = calculate(s.substr(i + 1, k - 1 - i));
                i = k;
            } else {
                calculate(ss, sign, cur);
                sign = s[i];
                cur = 0;
            }
        }
        calculate(ss, sign, cur);
        int ans = 0;
        while (!ss.empty()) {
            ans += ss.top();
            ss.pop();
        }
        return ans;
    }

    void calculate(stack<int>& ss, char sign, long cur) {
        if (sign == '+') {
            ss.push(cur);
        } else if (sign == '-') {
            ss.push(-cur);
        } else if (sign == '*' || sign == '/') {
            cur = sign == '*' ? ss.top() * cur : ss.top() / cur;
            ss.pop();
            ss.push(cur); 
        }
    }
};
```

227题代码：

```
class Solution {
public:
    int calculate(string s) {
        stack<int> ss;
        char sign = '+';
        long cur = 0;
        for (int i = 0; i < s.size() + 1; ++i) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * 10 + (s[i] - '0');
            } else {
                calculate(ss, sign, cur);
                sign = s[i];
                cur = 0;
            }
        }
        calculate(ss, sign, cur);
        int ans = 0;
        while (!ss.empty()) {
            ans += ss.top();
            ss.pop();
        }
        return ans;
    }

    void calculate(stack<int>& ss, char sign, long cur) {
        if (sign == '+') {
            ss.push(cur);
        } else if (sign == '-') {
            ss.push(-cur);
        } else if (sign == '*' || sign == '/') {
            cur = sign == '*' ? ss.top() * cur : ss.top() / cur;
            ss.pop();
            ss.push(cur); 
        }
    }
};
```
