### 解题思路
根据`?`与`:`的配对情况确定三元表达式的分割点，然后递归解决

### 代码

```cpp
class Solution {
public:
    string parseExp(const string& exp, int l, int r) {
        if (l == r) return exp.substr(l, 1);
        int n1 = 0;
        int n2 = 0;
        int i = l;
        for (; i <= r; ++i) {
            if (exp[i] == '?') {
                ++n1;
            } else if (exp[i] == ':') {
                ++n2;
            }
            if (n1 > 0 && n1 == n2) {
                break;
            }
        }
        return (exp[l] == 'T') ? parseExp(exp, l + 2, i - 1) : parseExp(exp, i + 1, r);
    }
    string parseTernary(string expression) {
        return parseExp(expression, 0, expression.size() - 1);
    }
};
```

![image.png](https://pic.leetcode-cn.com/c3a63ec1fc270e741de00adba968f02cd509677dfce24ad28784c022cc1445ef-image.png)
