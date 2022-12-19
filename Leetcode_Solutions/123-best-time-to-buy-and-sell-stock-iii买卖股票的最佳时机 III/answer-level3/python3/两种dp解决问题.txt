## [III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
你最多可以完成两笔交易

### 方法一
遍历划分点，把数组分成两部分，分别计算两部分的最大利润，相当于[第一题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

但是直接算会超时，这里用一个小优化，提前算好从左边到划分点的最大利润`left_max`和从有右边到划分点的最大利润`right_max`  
算`right_max`时注意要逆向思考，记录的是`max_price`

#### code
```py
class Solution:
    def maxProfit(self, prices) -> int:
        if not prices:
            return 0
        # left_max: [0,i] max profit
        left_max = [0] * len(prices)
        min_price = prices[0]
        for i in range(1, len(prices)):
            min_price = min(min_price, prices[i])
            left_max[i] = max(left_max[i - 1], prices[i] - min_price)

        # right_max: [i,len-1] max profit
        right_max = [0] * len(prices)
        max_price = prices[-1]
        for i in range(len(prices)-2, -1, -1):
            max_price = max(max_price, prices[i])
            right_max[i] = max(right_max[i + 1], max_price-prices[i])

        max_profit = 0
        for i in range(0, len(prices)):
            max_profit = max(max_profit, left_max[i]+right_max[i])
        return max_profit
```
### 方法二
[此类问题的通法](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

#### 状态定义
`f[i][j][k]`表示第i天，进行了j次交易，当前状态为k时的最大利润  
该题中$j<=2$  
k=0表示没有持有股票，k=1表示持有股票

#### 状态转移方程
```
f[i][j][0] = max(f[i - 1][j][1] + prices[i - 1], f[i - 1][j][0])
f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1])
```
#### 初始状态定义
```
f[i][0][0] = 0
f[i][0][1] = -inf
f[0][i][0] = -inf
f[0][i][1] = -inf
```
#### code
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        const int inf = 1 << 30;
        const int n = prices.size();
        int f[30000 + 5][3][2];
        for (int i = 0; i <= n; i++)
        {
            f[i][0][0] = 0;
            f[i][0][1] = -inf;
        }
        for (int i = 1; i <= 2; i++)
        {
            f[0][i][0] = -inf;
            f[0][i][1] = -inf;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                f[i][j][0] = max(f[i - 1][j][1] + prices[i - 1], f[i - 1][j][0]);
                if (j)
                {
                    f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
                }
            }
        }
        return max(max(f[n][0][0], f[n][1][0]), f[n][2][0]);
    }
};
```