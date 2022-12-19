### 解题思路
使用$i=1, 2,\ldots$遍历整个数组, 计算当天卖出的最大收益. 并更新第$i$天之前的最低股价(如果第$i-1$天的股价小于第$i-1$天之前的最低股价, 则将最低股价更新). 算法时间复杂度为$O(n)$, 空间复杂度为$O(1)$.
### 代码
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if(prices.size()<=1)
            return result;
        int min_idx = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i-1]<prices[min_idx])
                min_idx = i - 1;
            result = prices[i] - prices[min_idx] > result? prices[i] - prices[min_idx]: result;
        }
        return result;
    }
};
```