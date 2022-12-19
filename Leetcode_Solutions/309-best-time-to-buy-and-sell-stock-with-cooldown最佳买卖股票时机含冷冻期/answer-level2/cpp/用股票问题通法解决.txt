## [with cooldown](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。  
无限制交易次数  
状态转移方程要改一改  

原来的：
```
f[i][j][0] = max(f[i - 1][j][1] + prices[i - 1], f[i - 1][j][0])
f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1])
```

现在要把第二维状态压掉并改一下卖股票的那条方程，相当于要过两天才能收到卖股票的钱
```
f[i][0] = max(f[i - 2][1] + prices[i - 2], f[i - 1][0]);
f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i - 1]);
```
还要判断一下边界，因为如果最后一天卖出的话，就会收不到钱
```
f[n + 1][0] = max(f[n - 1][1] + prices[n - 1], f[n][0]);
return max(f[n + 1][0], f[n][0]);
```
### code
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
        if (!n){
            return 0;
        }
        int f[n + 5][2];
        for (int i = 0; i <= n + 1; i++)
        {
            f[i][0] = 0;
            f[i][1] = -inf;
        }
        for (int i = 1; i <= n; i++)
        {
            if (i >= 2)
            {
                f[i][0] = max(f[i - 2][1] + prices[i - 2], f[i - 1][0]);
            }
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i - 1]);
        }
        f[n + 1][0] = max(f[n - 1][1] + prices[n - 1], f[n][0]);
        return max(f[n + 1][0], f[n][0]);
    }
};
```