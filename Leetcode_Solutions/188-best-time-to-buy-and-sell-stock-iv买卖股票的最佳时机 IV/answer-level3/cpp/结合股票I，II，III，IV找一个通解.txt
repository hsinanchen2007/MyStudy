![20200209233821.png](https://pic.leetcode-cn.com/b57b36d20c93b645bf181a7ff729a0c91b617bdc4c73c1a546ba1991baa149fc-20200209233821.png)

建议做完121，122，123再做188,方法通用，“关注买卖的最大收益，不关注天数”。
建立长度为k*2的dp数组，偶买奇卖。
dp[0] = max(dp[0], -prices[i]); // 买 （第一次买，实际为 "0 - price[i]"）
dp[1] = max(dp[1], dp[0] + prices[i]); //卖
dp[2] = max(dp[2], dp[1] - prices[i]); // 买
...
dp[2*k] = max(dp[2*k], dp[2k - 1] + prices[i]); // 卖, 最后一个是偶数需要卖， 也因为卖掉是最划算的
最后 dp.back()就是结果。

k = 1可以解121题。
k = 2可以解123题。

```
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) { 
        if (!k || prices.empty()) return 0;
        if(k >= prices.size()/2) { //购买次数足够，用122题的方法, 防止k过大。
            int sum = 0;
            for (int i = 0; i < prices.size() - 1; ++i) {
                if (prices[i] < prices[i + 1]) sum += prices[i+1] - prices[i];
            }
            return sum;
        }
        vector<int> dp(2*k, INT_MIN); // 用123题的方法, k 从2变到任意值。 共k次，偶数买奇数卖
        dp[0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[0] = max(dp[0], -prices[i]); // first buy "0 - price[i]"
            for (int j = 1; j < 2*k; ++j) {
                if (j % 2) dp[j] = max(dp[j], dp[j-1] + prices[i]); // sell
                else dp[j] = max(dp[j], dp[j-1] - prices[i]); // buy
            }
        }
        return max(0, dp.back());
    }
};
```
