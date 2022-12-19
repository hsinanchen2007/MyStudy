### 解题思路
简单模拟

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)return 0;
        int now = prices[0];
        int ans = 0;
        
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > now){ans += prices[i]-now;now = prices[i];}
            else now = prices[i];
        return ans;
    }
};
```