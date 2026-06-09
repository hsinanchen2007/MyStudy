注意, 本题由于 k 的大小可以非常大, 所以在声明 dp 数组前, 一定要先判断 k 的大小, 如果超过范围, 则要转换为无限次的股票买卖, 否则会导致爆栈.

**C++ 实现:**
```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        //std::vector<std::pair<int, int>> dp(k+1, {-prices[0], 0});
        // 这里有一个隐藏很深的 bug, 就如果 k 的值很大, 就会直接把栈爆掉!!
        // 所以应该按照 k 值做优化, 将 vector 声明在 if 语句内部
        if (k < prices.size() / 2)  {
                std::vector<std::pair<int, int>> dp(k+1, {-prices[0], 0});
                for(int i=1;i<prices.size();i++)
                {
                    for(int j=1; j < k+1; j++)
                    {
                        int hold = std::max(dp[j].first, dp[j-1].second-prices[i]);
                        int not_hold = std::max(dp[j].second, dp[j].first+prices[i]);
                        dp[j].first = hold; dp[j].second = not_hold;
                    }
                }
            return dp[k].second; //max(dp[k].first, dp[k].second);
        } else  {
            std::pair<int, int> dp = {-prices[0], 0};
            for (int i=1; i<prices.size(); i++) {
                int hold = std::max(dp.first, dp.second-prices[i]);
                int not_hold = std::max(dp.second, dp.first+prices[i]);
                dp.first = hold; dp.second = not_hold;
            }
            return dp.second;
        }
    }
};
```

**Python 实现:**
```py
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if len(prices) <= 1: return 0
        if (k < len(prices) // 2) :
            dp = [[-prices[0], 0] for i in range(k+1)]
            for price in prices[1:]:
                for i in range(1, k+1):
                    dp[i] = [max(dp[i][0], dp[i-1][1]-price), max(dp[i][1], dp[i][0]+price)]
            return dp[k][1]
        else:
            dp = [-prices[0], 0]
            for price in prices[1:]:
                dp = [max(dp[0], dp[1]-price), max(dp[1], dp[0]+price)]
            return dp[1]
```
