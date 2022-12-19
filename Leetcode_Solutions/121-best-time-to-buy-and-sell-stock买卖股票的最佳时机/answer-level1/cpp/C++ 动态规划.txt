```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int lowstprice=prices[0],result=INT_MIN;
        for(int i=1;i<prices.size();++i){
            if(result<prices[i]-lowstprice){
                result=prices[i]-lowstprice;
            }
            lowstprice=min(lowstprice,prices[i]);
        }
        return result>0?result:0;
    }
};
求出在第i天卖出时所能获得的最大收益，一次遍历求出最大值，若小于0，则无法获益返回0；否则，返回最大收益
```
