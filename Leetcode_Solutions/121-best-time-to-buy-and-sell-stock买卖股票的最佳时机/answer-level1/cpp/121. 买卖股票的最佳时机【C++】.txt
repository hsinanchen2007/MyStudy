### 解题思路

这个题其实不是第一次遇上了，初学C++的时候就做过这个题，有几个需要注意的地方是：

- 需要判别**数组为空**的情况，此时利润为0可以直接返回；
- **不能在买入股票前卖出股票**，所以不是单纯找数组的最小值、最大值；
- 股票价格起伏不定，阶段性的买入卖出获得的是阶段性的最大利润，所以在题目要求“**最多只允许完成一笔交易**”的情况下，要始终保持利润最大化。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int profit = 0;//利润
        int buy = prices[0];//买入价格
        int sold = prices[0];//售出价格
        for (auto price : prices) {
            if (price < buy) {
                buy = price;
                sold = price;
            }
            if (price > sold) {
                sold = price;
                profit = (sold - buy) > profit ? (sold - buy) : profit;
            }
        }
        return profit;
    }
};
```