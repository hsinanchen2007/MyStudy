### 解题思路
dp：dp[i][0]表示第i天手上没有股票，dp[i][1]表示第i天手上持有股票
- dp[i][0]只能由两种情况推出：①前一天手上就没有股票，即dp[i-1][0]；②前一天手上有股票，但是今天卖了，那么手里会在昨天的基础上获得利润，即dp[i-1][1]+prices[i]-fee;
- 同理，dp[i][1]也是只能由两种情况推出。
- 因为每天的两种情况都列出了，即买卖所有情况都比较了一遍，截止到每天的利润最多的情况就是有无股票的情况中的一种。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<prices.size();i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);//第i天手里无股票
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);//第i天手里有股票
        }
        return max(dp.back()[0],dp.back()[1]);
    }
};
```
贪心：每次找到最大的利益。
- 当利润超过手续费时就将此股价列入备选的卖出价，如果遇到了更高的就更新备选卖出价。
- 如果没有备选的卖出解且遇到的更低的买入价，就把买入价更新。
- 如果有了备选的卖出价，然后又遇到了一个“比较低”的价格，就将上次买入的股票按备选卖出价套现，更新买入价，删除备选卖出价。
- 较低的价格是指 备选卖出价-较低价>手续费
```
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int lastin=prices[0],lastout=-1,res=0;
        for(int p : prices){
            if(lastout-p>fee){
                res+=lastout-lastin-fee;
                lastout=-1;
                lastin=p;
            }
            if(lastout!=-1&&p>lastout) lastout=p;
            if(lastout==-1&&p-lastin>fee) lastout=p;
            if(lastout==-1&&p<lastin) lastin=p;
        }
        if(lastout!=-1&&lastout-lastin>fee) res+=lastout-lastin-fee;
        return res;
    }
};
```
