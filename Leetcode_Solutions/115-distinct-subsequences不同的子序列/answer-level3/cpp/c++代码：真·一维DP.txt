![捕获.PNG](https://pic.leetcode-cn.com/4788195432f1a95736ac203fa22617f76d92261e3f26c05f9a5ceb543003fe6e-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        long dp[n + 1] = {0};
        long pre, tmp;
        for(int i = 0; i <= m; i++)
            for(int j = 0; j <= n; j++)
            {
                tmp = dp[j];
                if(j == 0) dp[j] = 1;
                else if(i == 0) dp[j] = 0;
                else if(s[i - 1] == t[j - 1]) dp[j] += pre;
                pre = tmp;
            }
        return dp[n];
    }
};
```

### 解题思路
观察状态转移方程就可以得出