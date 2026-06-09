这道题的主体通解部分用10行就可以搞定：
```c++
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int N = prices.size();
        if(N == 0) return 0;
        vector<int> dp(N, 0);
        while(k-- > 0)
        {
            for(int i = 1; i < N; ++i)
                dp[i] = max(dp[i - 1] - prices[i - 1] + prices[i], dp[i]);
            for(int i = 1; i < N; ++i)
                dp[i] = max(dp[i], dp[i - 1]);
        }
        return dp[N - 1];
    }
};
```

```c++
while(k-- > 0)
{
    //第1个for循环中，dp[i]代表第i天完成前k次交易所能获得的最大价值。
    //第2个for循环中，dp[i]代表前i天完成前k次交易所能获得的最大价值。
}
```
第1个for循环中：
```c++
dp[i] = max(dp[i - 1] - prices[i - 1] + prices[i], dp[i]);
```
dp[i]的值有两种可能：
第一，第i天完成第k笔买和卖，第k笔收益为0。
第二，第i天完成第k笔的卖出，之前的一些天完成其他交易。满足这种要求的所有情况，都能和第i-1天完成第k笔交易的情况建立一对一的关系，只是第k笔交易的卖出价格由prices[i - 1]变为了prices[i]。所以dp[i] = dp[i - 1] - prices[i - 1] + prices[i]。

以上是算法的完全思路，但是leetcode上的最后一个样例设计的不太好，k=1e9，这个样例对本题的理解没有半毛钱的帮助，只是为了卡时间而设计的，所以需要加入特殊判定：
```c++
if(k >= N / 2)
{
    ret = 0;
    for(int i = 1; i < N; ++i)
    {
        if(prices[i] > prices[i - 1])
            ret += prices[i] - prices[i - 1];
    }
    return ret;
}
```

于是最终的答案变成了：
```c++
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int N = prices.size();
        if(N == 0) return 0;
        if(k >= N / 2)
        {
            ret = 0;
            for(int i = 1; i < N; ++i)
            {
                if(prices[i] > prices[i - 1])
                    ret += prices[i] - prices[i - 1];
            }
            return ret;
        }
        vector<int> dp(N, 0);
        while(k-- > 0)
        {
            for(int i = 1; i < N; ++i)
                dp[i] = max(dp[i - 1] - prices[i - 1] + prices[i], dp[i]);
            for(int i = 1; i < N; ++i)
                dp[i] = max(dp[i], dp[i - 1]);
        }
        return dp[N - 1];
    }
};
```
