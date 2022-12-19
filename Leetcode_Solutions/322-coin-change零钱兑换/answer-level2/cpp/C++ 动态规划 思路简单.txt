### 解题思路
![image.png](https://pic.leetcode-cn.com/015d462caa27c6d6aba08a7a2142d28f547700240e6df1da2f9831b478b6a36e-image.png)


### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    dp[i] = std::min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1: dp[amount];
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/729b9e5825ad4222cf15fe745ea598b6b1ec8bc22b2565fc9cb98bc0d499ab57-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
