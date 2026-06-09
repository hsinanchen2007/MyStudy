### 解题思路
记录历史最低点作为买入点，遍历数组假设每天卖出能挣的钱，即可得到利润最大值

### 代码

```cpp
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        if (size < 2)
            return 0;
        int min = prices[0];
        int max = 0;
        for (int i = 1; i < size; i++)
        {
            max = max < (prices[i] - min) ? (prices[i] - min) : max;
            min = prices[i] < min ? prices[i] : min;
        }
        return max;
    }
};
```