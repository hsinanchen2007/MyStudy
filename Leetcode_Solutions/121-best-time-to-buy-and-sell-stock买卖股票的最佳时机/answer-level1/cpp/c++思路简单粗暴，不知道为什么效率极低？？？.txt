### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() < 2) return 0;
        int res = 0;
        int cur = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            res = max(res, prices[i] - cur);
            cur = min(cur, prices[i]);
        }
        return res;  
    }
};

```