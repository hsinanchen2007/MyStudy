### 解题思路
这题和279题 完全平方数几乎是一样的，若采用贪心算法，用较大的面额先去支付是行不通的
+ 设想 amount = 12,coins =[1,4,9],采用贪心算法为9+1+1+1+，实际为4+4+4

所以，首先将dp数组值均设为amount+1，dp[i]表示i元需要的最小钱张数，dp[i] = amount+1 表示无穷大，可理解为该值没有方法表示。（若1 in coins，dp[i]=amount,故任何情况下dp[i]<=amount）.
### 遍历所有的coins,rs为遍历所有coin的最终dp[i]。对每种遍历，表示选与不选(实在选不了才不选)该coin，
+ i(dp数组的任意下标) - coin<0表示选不起该值（实在选不了），直接换下一硬币,即不选.
+ 若选该coin。比较rs,dp[i-coin]+1,取最小值.
+ 注意dp[i] = amount+1,表示该值不能被表示。所以若rs初值为amount+1，dp[i-coin]+1在i-coin不能被表示的情况下是amount+2，rs为原值amount+1，即不能表示.


### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i=1;i<amount+1;i++)
        {
            int rs = amount+1;
            for(auto j:coins)
            {
                 if(i-j<0) continue;
                 if(dp[i-j]+1<rs)
                    rs = dp[i-j]+1;
            }
            dp[i] = rs;
        }
        if(dp[amount]==amount+1)
            return -1;
        return dp[amount];
    }
};
```