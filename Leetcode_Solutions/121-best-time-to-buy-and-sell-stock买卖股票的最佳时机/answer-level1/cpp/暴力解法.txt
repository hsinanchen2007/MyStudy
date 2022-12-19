### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
  
        int Min = 1e9;
        int profit = 0;
        
        for(int j = 0; j < prices.size(); j++){
            profit = max(profit,prices[j] - Min);
            Min = min(Min,prices[j]);
        }
        if(profit < 0)
        profit = 0;
        return profit;
  }
};
```