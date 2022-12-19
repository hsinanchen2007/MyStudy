### 解题思路
关注微信公众号'码农黑板报' 获取更多题解
![image.png](https://pic.leetcode-cn.com/b14831484e93c9e1381e8f1ba155ddd64eef8d276128545edab6fa37923c6141-image.png)

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if (n <= 1) {
            return 1;
        }
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        return dp[n];
    }
};
```