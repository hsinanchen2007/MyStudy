因为本题中规定买入，卖出和冷冻操作，规定上一次卖出和下一次买入之间需要至少一天的冷冻期，因此我们定义三种状态sell、buy和cooldown，分别对应了到第i天为止最后一个操作是买入、卖出和冷冻所对应的最大利润，则状态转移方程如下：

1. sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
2. buy[i]=max(buy[i-1],cooldown[i-1]-prices[i]);
3. cooldown[i]=max(cooldown[i-1],max(sell[i-1],buy[i-1])).
代码如下：
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n=prices.size();
        vector<int> sell(n,0);
        vector<int> buy(n,0);
        vector<int> cooldown(n,0);
        buy[0]=-prices[0];
        for(int i=1;i<n;i++){
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
            buy[i]=max(buy[i-1],cooldown[i-1]-prices[i]);
            cooldown[i]=max(cooldown[i-1],max(sell[i-1],buy[i-1]));
        }
        return sell.back();
    }
};
```