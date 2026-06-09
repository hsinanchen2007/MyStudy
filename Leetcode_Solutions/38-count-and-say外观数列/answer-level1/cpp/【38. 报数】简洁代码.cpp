### 思路
首先要读懂题意，每次下一个数为前一个数的读法。即需要统计上一个数中相邻相同元素的个数。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        while (--n) {
            string cur;
            for (int i = 0; i < res.size(); ++i) {
                int cnt = 1;
                while (i + 1 < res.size() && res[i] == res[i + 1]) {
                    ++cnt;
                    ++i;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
};
```