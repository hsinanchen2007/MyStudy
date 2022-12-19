后一个比前一个大就要操作买入卖出
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        vector<int> val(prices.size(), 0);
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i - 1])
                val[i] = val[i - 1] + (prices[i] - prices[i - 1]);
            else
                val[i] = val[i - 1];
        }
        return val[prices.size() - 1];
    }
};
```
