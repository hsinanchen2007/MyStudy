```
class Solution {
public:
    int calculate(string s) {
        s += "+";
        if (s.empty()) return 0;
        stack<int> vals;
        stack<char> ops;
        int val = 0;
        for (auto c : s) {
            if (c == ' ') {
                continue;
            } else if (c >= '0' && c <= '9') {
                val *= 10;
                val += c - '0';
            } else {
                vals.push(val);
                val = 0;
                if (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
                    int v1 = vals.top();
                    vals.pop();
                    int v2 = vals.top();
                    vals.pop();
                    char op = ops.top();
                    ops.pop();
                    int v = (op == '*') ? (v2 * v1) : (v2 / v1);
                    vals.push(v);
                }
                ops.push(c);
            }
        }
        vals.push(val);
        int res = 0;
        while (!ops.empty()) {
            int sign = ops.top() == '-' ? -1 : 1;
            ops.pop();
            int v = vals.top();
            vals.pop();
            res += sign * v;
        }
        if (!vals.empty()) res += vals.top();
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ac45544a3e98687bcf842e99f687b55107f2f992393517082a17591a328fb5e4-image.png)


