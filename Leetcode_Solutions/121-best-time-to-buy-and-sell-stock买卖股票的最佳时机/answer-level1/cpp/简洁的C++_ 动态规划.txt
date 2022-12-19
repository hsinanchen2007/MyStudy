## 动态规划
1. 找到状态转移方程：`res = max(res, prices[i] - min_val);`，`res`为前i天的最大收益，`min_val`为前i天的最小值。
2. 初始化状态量：`res = 0;`, `min_val = INT_MAX;`
代码如下：
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_val = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            min_val = min(min_val, prices[i]);
            res = max(res, prices[i] - min_val);
        }
        return res;
    }
};
```
