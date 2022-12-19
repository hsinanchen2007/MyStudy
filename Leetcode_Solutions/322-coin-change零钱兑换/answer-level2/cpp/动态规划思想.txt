### 解题思路
动态规划
dp[i] 表示组成总金额数为i的最小硬币数
dp[i] = {min(dp[i-c])(for c in coins)}+1

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i <= amount;i++){
            int minct = INT_MAX;
            for(auto c:coins){
                if(i-c>=0 && dp[i-c] >= 0)
                    minct = min(dp[i-c],minct);
            }
            if(minct!=INT_MAX)
                dp[i] = minct+1;
            else
                dp[i] = -1;
        }
        return dp[amount];
    }
};
```