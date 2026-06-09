### 解题思路
4 ms, 在所有 C++ 提交中击败了97.62%的用户

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxprofit = 0;
        int n = prices.size() - 1;
        for (int i = 0; i < n ; ++i) 
        {
            if (prices[i] < prices[i + 1])
                maxprofit += prices[i] - prices[i+1];
        }
        return -maxprofit;
    }
};
```