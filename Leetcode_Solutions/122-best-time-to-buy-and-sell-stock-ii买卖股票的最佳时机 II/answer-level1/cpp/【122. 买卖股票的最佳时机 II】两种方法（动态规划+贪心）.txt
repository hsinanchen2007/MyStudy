## 思路一：动态规划
### 代码
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int size = prices.size();        
        vector<int> sold(size), hold(size);
        hold[0] = -prices[0];
        int res = 0;
        for (int i = 1; i < size; ++i) {
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
            sold[i] = max(sold[i - 1], hold[i - 1] + prices[i]);
        }
        return sold[size - 1];
    }
};
```

## 思路二：贪心
### 代码
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int size = prices.size();        
        int res = 0;
        for (int i = 1; i < size; ++i) {
            if (prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;        
    }
};
```

