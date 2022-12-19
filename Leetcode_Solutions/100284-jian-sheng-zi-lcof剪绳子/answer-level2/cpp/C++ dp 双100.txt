### 解题思路
边界条件：dp[1] = dp[2] = 1，表示长度为 2 的绳子最大乘积为 1；
状态转移方程：dp[i] = max(dp[i], max((i - j) * j, j * dp[i - j]))

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        vector<int>dp(n+1,0);
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<n+1;i++){
            for(int j=0;j<=i/2;j++){
                dp[i] = max(dp[i], max((i - j) * j, j * dp[i - j]));
            }
        }
        return dp[n];
        

    }
};
```