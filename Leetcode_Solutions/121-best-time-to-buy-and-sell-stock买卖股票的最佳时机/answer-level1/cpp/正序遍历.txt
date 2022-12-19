### 解题思路
正序遍历一次数组，记录截止到目前卖出股票时的最大收益和最低购买价格
时间复杂度o(n), 用到了常数个临时变量，空间复杂度为o(1)

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int buyprices = prices[0];
        int maxprofit = 0;

        for(int i : prices){
            buyprices = min(buyprices, i);
            maxprofit = max(maxprofit, i - buyprices);
        }
        return maxprofit;
    }
    
};
```