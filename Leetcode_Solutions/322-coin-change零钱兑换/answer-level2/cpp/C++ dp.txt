### 解题思路
1、设dp[i]为凑够i钱数目的时候最小的硬币数。
2、那么dp[i] = 1 + min(dp[i-a], dp[i-b], dp[i-c], ....), 其中a、b、c为硬币的面额。
3、我们需要初始化dp数组，首先既然是求最小值，那dp数组的初始值可以设置为INT_MAX。当i为其中一种硬币面额的时候，这个时候个数肯定是1最小的。另外当如果dp[i]是INT_MAX的时候，注意这个数其实是无效的，不能加1.

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp = vector<int>(amount+1, INT_MAX);
        sort(coins.begin(), coins.end());
        for (int i=0; i<=amount; i++) {
            for (auto c : coins) {
                if (i - c < 0) {
                    continue;
                } else if (i == c) {
                    dp[i] = 1;
                }
                dp[i] = min(dp[i], dp[i-c] != INT_MAX ? dp[i-c] + 1 : INT_MAX);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
```