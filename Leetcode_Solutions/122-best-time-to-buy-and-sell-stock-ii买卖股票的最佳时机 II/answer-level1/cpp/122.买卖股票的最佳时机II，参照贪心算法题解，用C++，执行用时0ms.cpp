### 解题思路
贪心算法，得到所有正利润。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* Greedy Algorithm */

        if(prices.size() < 2) return 0;

        int profit_max = 0;
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i){
            profit = prices[i] - prices[i-1];
            if(profit > 0){
                profit_max += profit;
            }
        }
        return profit_max;

    }
};
```