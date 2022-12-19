### 解题思路
此处撰写解题思路
这是一位大神的题解笔记哦，不是我的，真的讲的特别好，贪心的证明、动态规划的设计都……哇塞~的那种感觉，放在这里方便我以后忘记了再看看~
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/
嗯……我第一次转载别人的，要注明“侵权删”，竖起三根手指！

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;       
        int out=0;
        /*动态规划算法*/
        int sell=0, buy=-prices[0];
        int presell=sell, prebuy=buy;
        for(int i=1; i<n; i++){
            sell=max(presell, prebuy+prices[i]);
            buy=max(buy, presell-prices[i]);
            presell=sell, prebuy=buy;
        }
        return sell;
        /*动态规划算法*/
        
        /* 贪心算法*/
        /* for(int i=1; i<n; i++){
            if(prices[i]-prices[i-1]>0) out += prices[i]-prices[i-1];
        return out;
        }贪心算法*/

        /*最原始的笨办法*/
        /*int dp[2][n+1];
        dp[0][0]=0;
        dp[1][0]=0;
        for(int i=1; i<=n; i++){
            dp[0][i]=0;
            for(int j=i-1; j>0; j--){
                if(prices[j-1]<prices[i-1])
                    dp[0][i]=max(dp[0][i], dp[1][j-1]+prices[i-1]-prices[j-1]);
            }
            dp[1][i]=max(dp[1][i-1], dp[0][i]);
            out = max(out, dp[1][i]);
        return out;
        }最原始的笨办法*/

    }
};
```