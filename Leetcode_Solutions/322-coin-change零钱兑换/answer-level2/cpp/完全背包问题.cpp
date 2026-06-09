一枚老菜鸡，为了纪念我第一次自己写出了状态方程，我一定要发一篇题解，老泪纵横啊
虽然写的过程有一些细节没处理好，但是还是被自己感动到了>~<

```
class Solution {
public:
    /*
        由题意可知，每个硬币只有选择和不选择两种情况，且每个硬币可以选择多次，说明这是一个完全背包问题。
        因此，直接套用完全背包问题的解题方式即可，只要将01背包问题的逆序遍历改成正序遍历得到dp数组

        1）dp[i]:表示组成金额为i时的最小硬币数
        2）状态方程：dp[i] = min(dp[i],dp[i-coin]+1),其中coin为coins[0~coins.size()-1]
        3）结果：res = dp[amount]  
    */

    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0)
            return -1;
        if(amount == 0)
            return 0;

        int dp[amount+1];
        memset(dp,0,sizeof(dp));

        for(auto &coin : coins)
        {
            for(int i = coin;i <= amount;i++)
            {
                //金额值和当前硬币值一样时，因此最少只需一个硬币
                if(i == coin)
                    dp[i] = 1;
                //如果金额值和当前硬币值不相等时
                else if(dp[i] == 0 && dp[i-coin] != 0)
                    dp[i] = dp[i-coin] + 1;
                else if(dp[i-coin] != 0)
                    dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
        return dp[amount] == 0 ? -1 : dp[amount];
    }
};
```
