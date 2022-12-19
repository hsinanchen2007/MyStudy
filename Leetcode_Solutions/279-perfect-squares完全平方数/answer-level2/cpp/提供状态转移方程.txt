### 解题思路
见代码注释

### 代码

```cpp
class Solution {
public:
    int numSquares(int n) {

        // 创建并初始化数组
        int dp[n+1]; dp[0] = 0;

        for (int i=1; i<=n; i++){
            dp[i] = i; // 初始化最坏情况, 全由1组成
            for (int j=1; i-j*j>=0; j++){
                // 状态转移方程
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
```