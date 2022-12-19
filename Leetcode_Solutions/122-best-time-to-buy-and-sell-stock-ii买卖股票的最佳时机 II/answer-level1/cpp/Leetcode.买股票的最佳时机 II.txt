### 解题思路
![timg.jfif](https://pic.leetcode-cn.com/82009f7ca8e7751db137465af9508317ccc6002f892666496fadbf12e18a6df3-timg.jfif)

多次买卖的条件下，怎样才能收益最高呢？从上图来说，股票曲线中所有斜率为正的线段恰好为你买入卖出的时间。将结果累加，极为最大收益。与一次买卖不同的是你有多次机会，见好就收才是王道。

贪心算法解决此题目；判断每两天的价格差，价格差大于0 就进行一次买卖，如果期间天数连续价格差为正，则视为最低点买入，最高点卖出。

### 代码

```cpp


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int max_profit = 0;
        for(int i = 0; i < prices.size()-1; i++)
        {
            if(prices[i] < prices[i+1])
                max_profit += prices[i+1] - prices[i];
        }
        return max_profit;
    }
};
```