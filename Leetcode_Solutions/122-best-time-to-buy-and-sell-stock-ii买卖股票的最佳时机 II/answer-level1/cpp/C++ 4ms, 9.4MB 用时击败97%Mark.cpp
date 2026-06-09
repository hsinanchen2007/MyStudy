### 解题思路
贪心

![image.png](https://pic.leetcode-cn.com/82bad0bde713bd6df9560079c629221d37eaac4ed5a7af0fbcaef0d33a61cd74-image.png)

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 特殊情况处理
        if(prices.size() == 0) return 0;
        // st 中存放买入价
        int st = prices[0];
        // price[now] 为卖出价
        int now = 1;
        int ans = 0;
        while(now < prices.size())
        {
            // 如果卖出价低于买入价，则不盈利，因此将买入日后移一日
            while(now < prices.size() && prices[now] < st)
            {
                st = prices[now];
                now ++;
            }
            if(now >= prices.size()) return ans;
            // 如果卖出价还可以更高，后移卖出日
            while(now + 1 < prices.size() && prices[now + 1] > prices[now]) now ++;
            ans += prices[now] - st;
            now ++;
            // 下一个买入日必至少为卖出日的后一天
            if(now >= prices.size()) return ans;
            st = prices[now];
            now ++;
        }
        return ans;
    }
};
```