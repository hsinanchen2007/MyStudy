### 解题思路
哈哈哈 参考别人的答案   真精彩

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        //借鉴自答案精选 日后再学习
    // 数组大小为 amount + 1，初始值也为 amount + 1
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 0; i < dp.size(); i++) {
        // 内层 for 在求所有子问题 + 1 的最小值
        for (int coin : coins) {
            // 子问题无解，跳过
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
```