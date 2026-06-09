### 解题思路


### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int size = prices.size();

        int dp_i_0 = 0;
        int dp_i_1 = numeric_limits<int>::min();

        for(int i = 0; i < size; i++) {
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = std::max(dp_i_1, -prices[i]);
        }

        return dp_i_0;
    }
};
```