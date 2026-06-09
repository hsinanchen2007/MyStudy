### 解题思路
求出转移方程，直接动态规划
![image.png](https://pic.leetcode-cn.com/d98199cc659649789e78aa5fddb33f461b5ce5b4b66fc4c50783cc25d07c31e6-image.png)

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() ) {
            return 0;
        }
        if (s.front() == '0') {
            return 0;
        }
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.size(); i++) {
            int x = 0;
            int y = 0;
            if (s[i - 1] != '0') {
                x = dp[i - 1];
            }
            if (s.substr(i - 2, 2) >= "10" && s.substr(i - 2, 2) <= "26") {
                y = dp[i - 2];
            }
            dp[i] = x + y;
        }
        return dp[s.size()];
    }
};
```