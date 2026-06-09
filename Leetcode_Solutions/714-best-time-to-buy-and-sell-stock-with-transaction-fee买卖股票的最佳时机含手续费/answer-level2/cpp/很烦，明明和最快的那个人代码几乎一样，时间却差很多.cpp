### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        std::ios::sync_with_stdio(false);   // 我简直是要气死了，我没加这句话，200ms，加了44ms，超越100%
        int size = prices.size();
        if(size == 0)
            return 0;
        int dp_0 = 0;
        int dp_1 = -prices[0] - fee;
        for(int i = 1; i < size; ++i)
        {
            int temp = dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, temp - prices[i] - fee);
        }
        return dp_0;
    }
};
```