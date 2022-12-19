### 解题思路
首先，上完全背包公式:dp(i,v)=max{dp(i-1,v),dp(i,v-wi)+vi}.
然后，结合此题分析，要求是物品刚好装满（即硬币凑整），那么初始化就应该是非法值（如INT_MAX，也许越界，所以只在amount上做了文章）。又要求利益最小（最少硬币），所以显然是min，值得注意的是，此处每个硬币的价值都为1（算是一个隐含条件吧），重量为其面额值。于是乎，加点简单判断条件来拦截非法情况，此题得解。

下面谈谈，对完全背包的一点感悟。与01不同，完全讲究的是顺序遍历，即dp(v)从0到c的逐个dp(v)=max{dp(v),dp(v-wi)+vi},最后求得dp(c).

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        if(coins.empty())return -1;
        int len=coins.size();
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<len;j++){
                if(i-coins[j]<0)continue;
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        if(dp[amount]>amount)return -1;
        return dp[amount];
    }
};
```