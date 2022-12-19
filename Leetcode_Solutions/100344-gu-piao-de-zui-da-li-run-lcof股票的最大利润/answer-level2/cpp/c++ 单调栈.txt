```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0||prices.size()==1)return 0;
        auto prices2=prices;
        for(int i=prices2.size()-2;i>=0;--i){
            prices2[i]=max(prices2[i],prices2[i+1]);
        }
        int res=0;
        int min1=INT_MAX;
        for(int i=0;i<prices.size()-1;++i){
            min1=min(min1,prices[i]);
            res=max(res,prices2[i+1]-min1);
        }
        return res;
    }
};
```
