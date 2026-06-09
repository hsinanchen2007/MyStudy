prices：`[7, 1, 5, 3, 6, 4]`
修正前的 diff：`[0, -6, 4, -2, 3, -2]`
修正后的 diff: `[0, 0, 4, -2, 3, -2]`


以上各个数组的含义：
- prices：原数组
- 修正前的 diff：`diff[i] = prices[i] - prices[i-1]`，这里将 prices[0] 对应的差值定义为 0，即将 diff[0] 定义为 0
- 修正后的 diff：因为如果 prices 中的元素一直是递减的话，则对应的 diff 元素应该定义为 0，表示利润为 0

所以原问题变成了求解修正后 diff 数组中值大于 0 的元素之和。


```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;

        bool sale_in = false;
        int profit = 0;
        int diff[prices.size()];

        diff[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i-1] > 0) {
                diff[i] = prices[i] - prices[i-1];
                sale_in = true;
            } else {
                diff[i] = sale_in ? prices[i] - prices[i-1] : 0;
            }

            if (diff[i] > 0)
                profit += diff[i];
        }

        return profit;
    }
};
```
