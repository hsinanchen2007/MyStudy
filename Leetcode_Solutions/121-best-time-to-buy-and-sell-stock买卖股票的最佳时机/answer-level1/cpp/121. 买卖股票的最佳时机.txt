### 解题思路
原数组两个元素的最大差等于求差数组的最大子序和

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int last = 0, profit = 0;
        for(int i = 0; i < (int)prices.size() - 1; ++i){
            last = max(0, last + prices[i+1] - prices[i]);
            profit = max(profit, last);
        }
        return profit;
    }
};
```