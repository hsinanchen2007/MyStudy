### 解题思路
贪心法：取当前最优解

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int result = 0;
        for (int i=0; i<prices.size()-1; i++)
        {
            if (prices[i+1] > prices[i])
                result += prices[i+1] - prices[i];
        }
        return result;
    }
};
```