### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        priority_queue<int, vector<int>, greater<int>> qq;
        int res = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            qq.push(prices[i]);
            res = max(res, prices[i] - qq.top());
        }
        return res;
    }
};
```