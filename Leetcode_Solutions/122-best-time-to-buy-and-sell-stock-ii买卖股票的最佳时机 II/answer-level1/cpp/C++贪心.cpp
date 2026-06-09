看清楚题目要求，可以进行多次买卖
那么贪心的我只要有钱赚，我就卖出，然后当即买入，
有得赚我又立即卖出，再买入。
反正即使最后一手没卖出，我也不亏（如果考虑最后一手卖出与否，这道题应该变为中档题）
贴代码：
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int maxp=0;
        int present=prices[0];
        int profit;
        for(int i=1;i<prices.size();++i){
            //profit =prices[i]-present;
            if(prices[i]-present>0) {maxp+=(prices[i]-present);present=prices[i];}
            //maxp =max(maxp,profit);
            else present =prices[i];

        }
        return maxp;
    }
};
```
