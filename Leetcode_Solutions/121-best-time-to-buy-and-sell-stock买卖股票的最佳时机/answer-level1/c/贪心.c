1、维护一个全局最大收益和当天的最大收益
2、当发现当天最大收益大于全局最大收益时，更新全局最大收益
3、返回全局最大收益

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int iMax = 0;   //全局最大收益
        if(prices.size()>0)
        {
            int iLowPrice = prices[0];  //记录当天最低买入价格
            for(int i=1; i<prices.size(); i++)
            {
                if(prices[i]-iLowPrice>iMax)    //当天最大收益>全局最大收益，则更新全局最大收益
                {
                    iMax = prices[i] - iLowPrice;
                }

                if(prices[i]<iLowPrice) //当天价格比之前最低买入价格低，则更新最低价格
                {
                    iLowPrice = prices[i];
                }
            }
        }

        return iMax;
};
```
