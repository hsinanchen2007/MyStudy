一开始的思路是错的，只想着把最低的价格挑出来，并没考虑到股票买卖的差值，以为只要最小值后面没值了就返回0，怎么会有这种脑回路呢。。。
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low,high,profit,a=0;
        if(prices.size()<2) return 0;
        low=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<low){
                low=prices[i];
                a=i;
            }

        }
        high=prices[a];
        for(int j=a;j<prices.size();j++)
        {
            if(prices[j]>high){
                high=prices[j];
            }
        }
        return high-low;
    }
};
```
第二次自己写，哭聊。。。执行时间1秒多。。。
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int cost=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i;j<prices.size();j++){
                if(prices[j]>prices[i]&&(cost<prices[j]-prices[i]))
                {
                    cost=prices[j]-prices[i];
                }
            }
        }
        return cost;
    }
};
```
然后看了下题解。。。emmm。。。其实自己第一次想法改正一下就好了。。。
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int low=prices[0],profit=0;
        for(int i=0;i<prices.size();i++){
            if(low>prices[i]){
                low=prices[i];
            }

            else{
                profit=max(profit,prices[i]-low);
            }
        }
        return profit;
    }
};
```
最后，编程题果然像智力题。。。


