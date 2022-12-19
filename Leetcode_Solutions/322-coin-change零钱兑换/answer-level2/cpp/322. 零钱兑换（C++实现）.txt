### 解题思路
1. 核心思路
- 动态规划
2. 复杂度
- 时间复杂度：O(m*n)，其中m，n分别是硬币的种类数（即数组coins的大小），总金额amount
- 空间复杂度：O(n)，n即使总金额，又是辅助数组dp的长度

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 初始化amount+1个元素，多的用来保存dp[0] = 0
        // 初始化dp数组的值要比amount大，取amount+1即可
        int i,j,max;
        max = amount + 1;
        vector<int> dp(amount+1,max);
        dp[0] = 0;
        for(i = 1; i <= amount; i++)
        {
            for(j = 0; j < coins.size(); j++)
            {
                // 单个硬币的值必须要<=金额i,否则i-coins[j]会<0溢出
                if(coins[j] <= i)
                // 第二个dp[i]，是在j循环内前面已经遍历过的最小dp[i]
                // 将该dp[i]与“扣除本次硬币值coins[j]”剩下的dp值+1做比较，取最小的dp值
                // 当前硬币值为coins[j]，dp值扣除了coins[j]，相当于多了1个值为coins[j]的硬币
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        // 如果不存在，比如coins=[2], amount=3，由于没有coins[j]==1,所以dp[1]取默认最大值amount+1,必定大于amount，从而dp[3]>amount
        return  dp[amount] > amount? -1 : dp[amount];
    }
};
```