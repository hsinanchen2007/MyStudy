### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    //dp[i]:代表i金额的最优解
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int>dp;
        for(int i=0;i<=amount;i++)
        {
            dp.push_back(-1);
        }
        dp[0]=0;
        for(int i=1;i<=amount;i++)//递归金额1-6                     
        { 
            for(int j=0;j<coins.size();j++)//遍历面额 1, 2 ,5                
            {
                //如果这个金额有这样的面值，且减去该面值的金额已经组合成
                if(i>=coins[j]&&dp[i-coins[j]]!=-1)//i可以由coins[j]组合且dp[i-coins[j]]已经组合完成    
                {
                    //如果这个面值没有组合 或者 这个面值大于前面的金额组合更新
                    if(dp[i]==-1||dp[i]>dp[i-coins[j]]+1)//一张coins[j]+dp[i-coins[j]]    
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