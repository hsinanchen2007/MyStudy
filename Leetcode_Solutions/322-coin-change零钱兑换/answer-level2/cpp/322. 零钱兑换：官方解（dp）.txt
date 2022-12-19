### 状态转移方程
dp[amount] = 0, amount = 0;
dp[amount] = -1, amount < 0;
dp[amount] = min{dp[amount - coin]} + 1;

### 代码

```cpp
class Solution {
    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        return dpCoin(coins, amount, dp);
    }
    int dpCoin(vector<int>& coins, int amt, vector<int> &dp) {
        if(amt < 0) return -1;  // 边界1：金额小于0，不可能，返回-1
        if(amt < 1) return 0;   // 边界2：金额等于0，返回0；
        if(dp[amt] != 0) return dp[amt];    // 已经计算出了dp[amt]，直接返回

        int mindp = INT_MAX;
        for(int c: coins) {
            int res = dpCoin(coins, amt - c, dp);   // 状态转移：dp[amt] = min{dp[amt-c]} + 1
            if(res >= 0 && res < mindp) {
                mindp = res + 1;
            }
        }
        dp[amt] = (mindp == INT_MAX ? -1 : mindp);
        return dp[amt];
    }
};
```
![a.png](https://pic.leetcode-cn.com/986326fcd3a900e48a1c777b35e8debed13b19a87c8f33fc52af959c0e6d680b-a.png)
