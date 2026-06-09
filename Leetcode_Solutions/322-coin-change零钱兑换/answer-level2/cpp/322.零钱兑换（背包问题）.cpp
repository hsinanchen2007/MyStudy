### 解题思路
这题是典型的动态规划，背包问题
时间复杂度：O[SN]
空间复杂度：O[N]
### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //初始化数组
        //方法一：直接初始化vector
        vector<int> dp(amount+1,-1);
        //方法二：用for循环复制
        // for(int i=0;i<=amount;i++)
        // {
        //     dp.push_back(-1);
        // }
        //方法一比方法二的内存减少6M
        //开始递推
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0&&dp[i-coins[j]]!=-1)
                {
                    //dp[i]=getmin(dp[i-coins[j]])+1
                    if(dp[i]==-1||dp[i]>dp[i-coins[j]]+1)
                    {
                        dp[i]=dp[i-coins[j]]+1;
                    }
                }
            }
        }
        return dp[amount];
    }
};
```