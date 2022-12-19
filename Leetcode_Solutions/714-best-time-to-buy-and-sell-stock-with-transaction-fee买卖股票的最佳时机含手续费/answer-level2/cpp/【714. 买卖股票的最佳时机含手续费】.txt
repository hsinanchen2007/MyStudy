## 思路：动态规划
### 代码
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        vector<int> hold(size), sold(hold);
        hold[0] = -prices[0];
        for (int i = 1; i < size; ++i) {
            sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
        }
        return sold[size - 1];
    }
};
```

#### 优化空间
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;
        int size = prices.size();
        int sold = 0, hold = -prices[0];        
        for (int i = 1; i < size; ++i) {
            sold = max(sold, hold + prices[i] - fee);
            hold = max(hold, sold - prices[i]);
        }
        return sold;
    }
};
```
