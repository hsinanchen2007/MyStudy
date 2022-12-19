```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i + 1 < prices.size(); ++i) profit += max(prices[i + 1] - prices[i], 0);
        return profit;
    }
};
```
- 每次买完股票，第二天就出售掉
- 只要明天股票价格比今天高，今天就买入
- 买入和出售可以发生在同一天
