### 解题思路

因为没有交易手续费，没有交易数限制，于是我们就可以简单用贪心法，也就是明天价格比今天高，今天就买，第二天就卖。


```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() == 0 ) return 0;
        int profit = 0;
        int i = 0;
        while (i < prices.size() - 1){
            if (prices[i] < prices[i+1]){
                profit += prices[i+1] - prices[i];
            }
            i++;    
        }
        return profit;

    }
};
```