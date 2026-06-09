### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 3, -1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            int min_cnt = INT_MAX;
            for(int j = 0; j < coins.size() && coins[j] <= i; j++) {
                if (dp[i - coins[j]] != -1&&
                    dp[i - coins[j]] + 1< min_cnt){
                        min_cnt = dp[i - coins[j]] + 1;
                    }
            }
            dp[i] = min_cnt == INT_MAX ? -1 : min_cnt;

        }
        return dp[amount];
    }
};
```