### 解题思路
尾递归：当递归调用是整个函数体中最后执行的语句且它的返回值不属于表达式的一部分时，这个递归调用就是尾递归。
特点：
1、不会栈溢出：当编译器检测到一个函数调用是尾递归的时候，它就覆盖当前的活动记录而不是在栈中去创建一个新的。
2、效率：通过覆盖当前的栈帧而不是在其之上重新添加一个，这样所使用的栈空间就大大缩减了，这使得实际的运行效率会变得更高。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if (0 == n) return "";
        string ret = "1";
        return tailCountAndSay(n, ret);
    }

    string tailCountAndSay(int n, string &s) {
        if (1 == n) return s;
        string r = "";
        const char *cs = s.c_str();
        const char *c = cs;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (*c == *(cs + i)) {
                count ++;
                continue;
            }

            r.push_back('0' + count);
            r.push_back(*c); 
            c = cs + i;
            count = 1;
        }
        r.push_back('0' + count);
        r.push_back(*c);
        return tailCountAndSay(n - 1, r);
    }
};
```