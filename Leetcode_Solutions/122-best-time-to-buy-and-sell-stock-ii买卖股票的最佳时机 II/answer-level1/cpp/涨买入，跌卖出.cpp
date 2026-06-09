### 解题思路
开始涨的时候买入，开始跌的时候卖出
注意数组最后的卖出

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy;
        int buy_flag = 0;
        int earn = 0;
        int i;
        
        if (prices.empty())
            return 0;
        
        for (i = 0; i < prices.size() - 1; i++) {
            if (prices[i + 1] > prices[i]) {
                /* buy */
                if (buy_flag == 0) {
                    buy = prices[i];
                    buy_flag = 1;
                }
            } else {
                /* sale */
                if (buy_flag) {
                    earn += prices[i] - buy;
                    buy_flag = 0;
                }
            }
        }
        if (buy_flag)
            earn += prices[i] - buy;
        
        return earn;
    }
};
```