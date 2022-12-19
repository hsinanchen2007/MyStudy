### 解题思路
此题依然可以使用贪心思想求解。
因为题目要求最多不超过两次交易，因此可以价格序列正向贪心一次，反向贪心一次，然后取二者和的最大值即为答案。

![image.png](https://pic.leetcode-cn.com/c8f232e4a133a2c178fc37a5ddc77d4dd4f3503b1d004cbffc9bd61fe12156ac-image.png)

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int st = prices[0];
        vector<int> ans;
        ans.push_back(0);
        // 正向贪心，结果存储在 ans 中，注意此时范围是 1 ~ (size() - 2)，计算的是 prices[now] - buy，st 是当前最优买入价
        for(int i = 1; i < prices.size() - 1; i ++)
        {
            ans.push_back(max(prices[i] - st, ans[i - 1]));
            st = min(prices[i], st);
        }
        st = prices[prices.size() - 1];
        int outp = ans[prices.size() - 1];
        // 反向贪心，结果存储在 ans 中，注意此时范围是 (size() - 2) ~ 1，计算的是 sell - prices[now]，st 是当前最优卖出价 
        for(int i = prices.size() - 2; i > 0; i --)
        {
            outp = max(outp, st - prices[i] + ans[i]);
            st = max(prices[i], st);
        }
        return outp;
    }
};
```