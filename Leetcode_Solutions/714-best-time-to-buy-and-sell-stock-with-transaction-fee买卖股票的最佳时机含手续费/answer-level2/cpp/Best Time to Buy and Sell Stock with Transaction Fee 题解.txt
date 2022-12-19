### 解题思路
参考团灭

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if(len == 0){
            return 0;
        }

        int dp_i_0 = 0;
        int dp_i_1 = -prices[0];
        for(int i = 0; i < len; ++i){
            int pre_dp_i_0 = dp_i_0;
            // 卖出的时候扣除fee
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i] - fee);
            dp_i_1 = max(dp_i_1, pre_dp_i_0 - prices[i]);
        }

        return dp_i_0;
    }
};
```