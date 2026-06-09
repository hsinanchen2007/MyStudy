### 解题思路
# 动态规划
可以画出树
***主要是要限制一些条件***

***动态转移方程***
dp[i]=dp[i-nums[j]]+1;

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<int> dp(amount+1,-1); //dp[i]表示 组成i最少需要的硬币个数
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i>=coins[j] && dp[i-coins[j]]!=-1){ //有一些限制条件 i(amount)必须大于coins[j] 如果小的话就不能组成了  并且dp[i-coins[j]]不能等于-1 不能是初始值
                    if(dp[i]==-1 || dp[i]>dp[i-coins[j]]+1)  //dp[i]未被更新过 或者 dp[i]大于更新后的值
                        dp[i]=dp[i-coins[j]]+1;
                }
                
            }
        }
        return dp[amount];
        
    }
};
```