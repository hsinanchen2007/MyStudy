### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)return 0;
        vector<int> currMin(prices.size());  //用于维护当前的最低价格
        int minPrice, maxProfit;  //minPrice表示当前的最低价，maxProfit表示当前最大利润
        minPrice = 100000000;
        maxProfit = 0;
        for(int i = 0; i < prices.size(); ++i)
        {
            if(prices[i] < minPrice)  //如果当前买入价格比当前最低价还低
            {
                minPrice = prices[i];  //更新当前最低价
                currMin[i] = minPrice;  //currMin[i]表示i之前的最小价格
            }
            else
            {
                currMin[i] = minPrice;  //当前买入价格比当前最低价高，那当前最低价依旧是之前的最低价
            }
            if(prices[i]-currMin[i] > maxProfit)  //每次循环都将(当前卖出价格-当前最低价)和最大利润比较
                maxProfit = prices[i] - currMin[i];  //更新最大利润
        }
        return maxProfit;
    }
};
```