### 解题思路
看了其他人的此类dp思路，豁然开朗。
建议可以看看 
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems

另外的借鉴后翻译的中文版的
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-lab/

用dp解决
dp[i][0] 代表第i天不持有股票的收益，dp[i][1]代表第i天持有股票收益。
那么  
dp[i][0] = max(dp[i-1][1] + price, dp[i-1][0])
dp[i][1] = max(dp[i-2][0] - price, dp[i-1][1])

然后发现都是使用了前1天和2天的数据，所以可以用几个变量解决
dp[i][0] => dp_0, dp[i][1] => dp_1, dp[i-2][0] => dp_i_2

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = 0, dp_1 = INT_MIN, dp_i_2 = 0;
        for (int i=0; i<prices.size(); i++) {
            int temp = dp_0;
            dp_0 = max(dp_1 + prices[i] , dp_0);
            dp_1 = max(dp_i_2 - prices[i], dp_1);
            dp_i_2 = temp;
        }
        return dp_0;
    }
};
```