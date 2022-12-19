### 解题思路
![image.png](https://pic.leetcode-cn.com/de190b5c72f2224675e49ddd2dcf40df8440359aa83eb9b78e9d3aed1d06719a-image.png)
辅助栈方法，用栈存过往元素，遇到]触发拼接，然后重新扔入栈进行迭代
### 代码

```cpp
#include <stdlib.h>
class Solution {
public:
    string repeat(int n, string s) {
        string res;
        for (int i = 0; i < n; i++) {
            res += s;
        }
        return res;
    }
    string decodeString(string s) {
        int len = s.size();
        stack<string> ss;
        for (int i = 0; i < len; i++) {
            if (s[i] == ']') {
                string str;
                while (ss.top() != "[") {
                    str = ss.top() + str;
                    ss.pop();
                }
                ss.pop();
                string num;
                while (!ss.empty() && ss.top() >= "0" && ss.top() <= "9") {
                    num = ss.top() + num;
                    ss.pop();
                }
                string tmp = repeat(atoi(num.c_str()), str);
                ss.push(tmp);
                continue;
            }
            string c;
            c = c + s[i];
            ss.push(c);
        }
        string res;
        while (!ss.empty()) {
            res = ss.top() + res;
            ss.pop();
        }
        return res;
    }
};
```