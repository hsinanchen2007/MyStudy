### 解题思路
时间复杂O(n)，内存消耗常数空间。
![捕获.PNG](https://pic.leetcode-cn.com/ef01ac904e0528a4d9974463f74dec449794d0a72598e069eb5f9cd195b7544f-%E6%8D%95%E8%8E%B7.PNG)
循环n-1次，作为卖出股票的时间，tmp变量记录这一天之前的最低价格，也就是买入的最低价，计算当前这一天抛出股票时最多赚多少钱，prices[i]-tmp，然后更新res以及tmp。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;;
        int n = prices.size();
        int res = 0;
        int tmp = prices[0];
        for (int i = 1; i < n; i++) {
            res = max(res, prices[i] - tmp);
            tmp = min(tmp, prices[i]);
        }
        return res;

    }
};
```