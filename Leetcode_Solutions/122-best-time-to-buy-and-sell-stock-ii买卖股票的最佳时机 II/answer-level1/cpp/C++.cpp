### 解题思路

无

### 代码

```cpp
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = INT_MAX;
        int sell = INT_MIN;
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (buy > prices[i])
            {
                buy = prices[i];
                sell = prices[i];
            }
            else if (sell < prices[i])
            {
                sell = prices[i];
                ans = sell - buy;
                sum += ans;

                buy = prices[i];
            }
        }
        return sum;
    }
};
```