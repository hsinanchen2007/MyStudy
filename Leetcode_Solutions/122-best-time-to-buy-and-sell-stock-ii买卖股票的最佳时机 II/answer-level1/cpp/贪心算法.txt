### 解题思路
* 贪心算法的原理：分阶段的工作。即在每一个阶段都认为所做的决定是最好的，不考虑将来的后果（局部最优）
* 对于本题，只需要在市场价格比买入价格高时将其卖出，差价即为利润。抽象为数组形式，遍历整个数组，当`prices[i+1] > prices[i]`的时候，即到了卖出时刻。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int i32MaxProfit = 0;
        if (prices.size() == 0)
            return 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i + 1] > prices[i])
                i32MaxProfit += prices[i + 1] - prices[i];
        }
        return i32MaxProfit;
    }
};
```