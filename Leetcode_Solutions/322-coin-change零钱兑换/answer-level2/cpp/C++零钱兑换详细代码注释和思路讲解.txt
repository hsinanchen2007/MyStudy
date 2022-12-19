### 解题思路
F(X)=min（使用coins中的硬币种类平凑出X块钱的硬币数量）
则F（0）=0，因为0元只需要0个货币
当我们需要求解F（X)时，F（X）=MIN（F（X减去一个硬币的面值）+1）
只要尝试所有面值，就可以求出F（X)
以此类推，我么可以从1开始，一直算到所需要求解的值

### 代码

```cpp

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        //dp[n]的值为总价值n元时所需的最少的硬币数量
        //初始化dp使所有值为amount+1
        dp[0] = 0;
        //0元时所需货币数量为0
        for (int i = 1; i <= amount; ++i) {
            //i在这里相当于我们需要求的总值数，因为0已经被给出（0个货币），所以从1开始
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    //用于遍历所有的硬币
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
        //因为初始化所有的值为amount+1，如果到循环最后仍然没有更新值数
        //则视为无法用这几种硬币拼凑出所给的值
    }
};

```