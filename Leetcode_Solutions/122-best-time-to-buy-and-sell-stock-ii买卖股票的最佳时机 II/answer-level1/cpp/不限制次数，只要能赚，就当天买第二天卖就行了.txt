### 解题思路
不限制次数，只要能赚，就当天买第二天卖就行了
一次遍历
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2) return 0;
        int profit = 0;
        for(size_t idx = 1; idx < len; ++idx)
            profit += max(prices[idx] - prices[idx-1], 0);
        return profit;
    }
};
```