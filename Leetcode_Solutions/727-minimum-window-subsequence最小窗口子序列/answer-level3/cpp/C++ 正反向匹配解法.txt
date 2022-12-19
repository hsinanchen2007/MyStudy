# 思路：
1，从S的起点`i`先正向匹配找到符合条件的区间最小的终点`j`
2，从`j`反向匹配，找到最大的满足条件的新起点`k`
```C++ []
class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() < T.size()) return "";
        int NS = S.size();
        int NT = T.size();
        string res;
        int resLen = NS;
        for (int i = 0; i <= NS - NT; ++i) {
            if (S[i] != T[0]) continue;
            // 正向匹配
            int j = 0;
            while (i < NS && j < NT) {
                if (S[i] == T[j]) ++j;
                ++i;
            }
            if (j != NT) break;
            // 反向匹配
            int r = i;
            j = NT - 1;
            --i;
            while (j >= 0) {
                if (S[i] == T[j]) --j;
                --i;
            }
            ++i;
            if (r - i < resLen) {
                res = S.substr(i, r - i);
                resLen = r - i;
            } else {
                i = r - resLen;
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/2f81fc557340f8397fe65527f3bebfdb4e8d35c0c2d86b197c626b5c8286e825-image.png)
