### 解题思路
最简单动态规划  （关注微信公众号'码农黑板报' 获取更多题解）
![image.png](https://pic.leetcode-cn.com/1361359d49761da5148839ae8665f19a60887cba6bef8216ddb2ba26b58feb63-image.png)

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        if (n > 0) {
            dp[1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        return dp[n];
    }
};
```