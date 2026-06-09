### 解题思路
判断是否买入
记录卖出点的价格，若出现比其更高的价格，则更新当前最大收益dp[i]
思维漏洞：买入点可能更新，从而影响当前最大收益
需要一个变量记录当前最小prices，每个最小值，都是可能的买入点 

官方答案：不用动态规划
遍历一遍，记录历史最低点，当前最大利润。若当前价格减去最低点大于上一个的最大利润，更新当前最大利润。

官方的答案不用记录是否买入，我更新当前最大收益dp[i]的方式没有一步到位，没有必要记录卖出点……
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        vector<int> dp(n,0);//dp[0]存储最大收益
        int sold=0;int flag=0;
        int m=prices[0];//m存储买入价格
        for(int i=1;i<n;++i){
            dp[i]=dp[i-1];
            if(!flag){
                if(m<prices[i]){
                    sold=i;
                    dp[i]=prices[i]-m;
                    dp[0]=dp[i];
                    flag=1;
                }
            }   
            m=min(m,prices[i]); //每个最小值，都是可能的买入点   
            
            if(flag&&prices[i]>prices[sold]){
                dp[i]+=prices[i]-prices[sold];
                sold=i;
                dp[0]=dp[i];
            }
            if(prices[i]-m>dp[i]){//出现更大的收益且买入点与原来不同
                sold=i;
                dp[i]=prices[i]-m;
                dp[0]=dp[i];
            }
        }
        return dp[0];
    }
};
```
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {//对于vector,这样遍历代码更简洁，price即遍历到的prices[i]
            maxprofit = max(maxprofit, price - minprice);//更新maxprofit，一步到位，比我的快很多
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};
```
