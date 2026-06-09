### 解题思路
表达式求值第一反应想到栈。用数据栈(data)存储操作数，操作符栈(op)存储运算符。
这题需要注意的一个坑是由于减法操作不满足交换律和结合律，故应该从右往左遍历。因为从右往左入栈时，出栈才是从左往右的正常顺序。但由于从右往左遍历，就需要对操作数进行反转。

### 代码

```cpp
class Solution {
public:
    int calculate(string s) {
        stack<int> data;
        stack<char> op;
        int num = 0, n = 0;
        for (int i = s.size()-1 ; i >= 0 ; --i) {
            if (s[i] >= '0' and s[i] <= '9') {
                num += (s[i]-'0') * pow(10, n);  // 对操作数进行反转；
                ++n;
                continue;
            } else {
                // cout << num << endl;
                if (n > 0) {
                    data.push(num);
                }
                num = 0, n = 0;
            }
            if (s[i] == ' ') continue;
            if (s[i] == '+' || s[i] == '-' || s[i] == ')') {
                op.push(s[i]);
            } else if (s[i] == '(') {          // 先对括号内的表达式进行求值，结果存入数据栈；
                while (op.top() != ')') {
                    char opra = op.top();
                    op.pop();
                    int res = data.top();
                    data.pop();
                    if (opra == '+') {
                        res += data.top();
                    } else {
                        res -= data.top();
                    }
                    data.pop();
                    data.push(res);
                    // cout << res << endl;
                }
                op.pop();          // '(' 出栈
            }
        }
        if (isdigit(s[0])) {        // 左边第一个字符是数字时，说明最后一个num还未入栈；
            data.push(num);
        }
        // cout << num << endl;
        while (!op.empty()) {
            char opra = op.top();
            op.pop();
            int res = data.top();
            data.pop();
            if (opra == '+') {
                res += data.top();
            } else {
                res -= data.top();
            }
            data.pop();
            data.push(res);
            // cout << res << endl;
        }
        return data.top();
    }
};
```