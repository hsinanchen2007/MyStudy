解题思路：用两个变量分别存储【最低价格】和【最大利润】，每天用【当天的价格】和【最低价格】比较，取较小值作为新的【最低价格】，用【当天的价格】减去存储的【最低价格】得出【当天卖出的话所能获得的利润】，取【当天卖出的话所能获得的利润】和【最大利润】之间较大值作为新的【最大利润】。
```c++ []
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int res = 0;
        int low = prices[0];
        for(int i = 0;i<prices.size();++i){
            low = min(low,prices[i]);
            res = max(res,prices[i] - low);
        }
        return res;
    }
};
```




