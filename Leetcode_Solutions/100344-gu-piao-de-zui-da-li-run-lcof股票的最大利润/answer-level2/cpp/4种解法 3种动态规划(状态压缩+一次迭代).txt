### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    //第i个数字卖处 i之前最小值
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int res = max(0,prices[1] - prices[0]);
        int curmin = min(prices[0],prices[1]);    //[0,i-1] i
        for(int i=2;i<prices.size();i++)
        {
            res = max(res,prices[i] - curmin);
            curmin = min(prices[i],curmin);
        }
        return res;
    }
    //状态压缩+一次迭代
    int maxProfit0(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int res = 0;
        int len = prices.size();
        int pre = 0;
        for(int i=0;i<len-1;i++)
        {
            int cur = prices[i+1] - prices[i];
            if(pre > 0)
                cur = cur + pre;
            pre = cur;
            res = max(res,cur);
        }
        return res;
    }
    //动态规划 状态压缩
    int maxProfit1(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int res = 0;
        int len = prices.size();
        for(int i=0;i<len-1;i++)
        {
            prices[i] = prices[i+1]-prices[i];
        }
        prices[len-1] = 0;
        int pre = prices[0];
        res = max(pre,res);
        for(int i=1;i<len;i++)
        {
            int cur = prices[i];
            if(pre > 0)
                cur = cur + pre;
            res = max(res,cur);
            pre = cur;
        }
        return res;
    }
    //动态规划
    int maxProfit2(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int len = prices.size();
        for(int i=0;i<len-1;i++)
        {
            prices[i] = prices[i+1]-prices[i];
        }
        prices[len-1] = 0;
        //最大连续子序列问题
        //dp[i] 包含i序号的最大连续子序列的和
        //dp[i] = dp[i-1] + prices[i]{dp[i-1 > 0 ]} 
        vector<int> dp(len);
        int res = 0;
        dp[0] = prices[0];
        res = max(dp[0],res);
        for(int i=1;i<len;i++)
        {
            if(dp[i-1] > 0)
                dp[i] = dp[i-1] + prices[i];
            else
                dp[i] = prices[i];
            res =  max(res,dp[i]);
        }
        return res;
    }
};
```