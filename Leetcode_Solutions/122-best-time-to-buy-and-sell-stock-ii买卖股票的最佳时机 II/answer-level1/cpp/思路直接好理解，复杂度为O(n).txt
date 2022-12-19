### 解题思路
1、设置买入、卖出状态标记，因为不能同时买卖
2、选定买入和卖出的时机
    如果price[i] < price[i+1] 则可以买入，并设定买入标记
    如果一直递增不卖出，直到有下降点再下降点的前一天卖出；
    处理边界情况（比如一直递增和数组为空）

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int profit = 0;
        int pre_price = 0;
        int buy_idx = 0;
        int sell_idx = 0;
        bool buy_flag = false;
        bool sell_flag = false;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (buy_flag == false && prices[i] < prices[i + 1]) {
                buy_idx = i;
                buy_flag = true;
            }
            if (buy_flag && (prices[i] > prices[i+1])) {
                sell_idx = i;
                sell_flag = true;
            }
            if (buy_flag && sell_flag == false && i == prices.size() - 2) {
                sell_idx = i + 1;
                sell_flag = true;
            }
            if (buy_flag && sell_flag) {
                profit +=  prices[sell_idx] - prices[buy_idx];
                buy_flag = false;
                sell_flag = false;
            }
        }
        return profit;
    }
};
```