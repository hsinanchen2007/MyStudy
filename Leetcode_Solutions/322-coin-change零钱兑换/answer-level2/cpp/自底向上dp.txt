### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);//定义硬币数量上界，硬币数量不会大于总钱数。
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(auto x:coins)
            {
                if(i-x<0)//如果当前钱数小于当前硬币面值，则不能加入此硬币
                {
                    continue;
                }
                else
                {
                    dp[i]=min(dp[i],dp[i-x]+1);//凑成金额i所需的最少硬币数量，取凑成金额i-x所需硬币数再+1（加入了金额为x的一枚硬币）的最小值。
                }
            }
        }
        return (dp[amount]!=amount+1)?dp[amount]:-1;//如果dp[amount]==amount+1，则说明没有进入上面双重for循环的else内，说明没有合理的硬币能凑成金额amount，返回-1。
    }
};
```