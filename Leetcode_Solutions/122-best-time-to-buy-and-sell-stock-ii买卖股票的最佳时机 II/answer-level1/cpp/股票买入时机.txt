### 解题思路
当天股票价格大于当前天股票就卖出
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,buy=INT_MAX;
        if(prices.size()<2){
            return 0;
        }
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};
```