### 解题思路
遍历股价，记录历史最低点及历史最高收益，计算max(最低点买入当前卖出的收益，历史最高收益）

### 代码

```cpp
class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
            return 0;
        int min_price = prices[0];
        int max_profit = 0;
        for(int i = 0; i< n; i++){
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return max_profit;
    }
};

```