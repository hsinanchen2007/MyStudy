每次都有选与不选两种决策。
以dp[i]记录 钱为i时，所需的最少硬币个数
- 选择  此时就是 (i-当前硬币价值)所需要的最少硬币个数(dp[i-coin])加上当前选择的这个硬币个数(1) 也就是dp[i-coin] + 1
- 不选择 不选择当前硬币，此时还是剩i，所以此时的价值就是dp[i]。
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        // 没有钱凑不出来了
        dp[0] = 0;
        // 有钱就开始凑
        for(int i=1;i<dp.size();i++) {
            // i表示还有多少钱
            // 拿出硬币
            for(auto coin : coins) {
                if(i-coin<0) continue;
                // 每次都有选与不选，不选此时钱还是i，否则此时钱就变为i-coin
                // dp[i]表示剩余钱为i的时候所需的最少硬币个数
                dp[i] = min(dp[i],1 + dp[i-coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }

};
```