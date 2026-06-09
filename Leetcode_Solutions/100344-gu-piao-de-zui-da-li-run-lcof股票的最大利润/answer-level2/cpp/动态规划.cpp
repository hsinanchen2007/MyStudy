### 解题思路
从每个结点向前看，都有一个最小buyprice，现在我们假设要在该结点卖出，需要考虑的是buyprice是否小于当前节点的值，如果小于即可计算在当前节点卖出的利润profit，比较当前profit和之前维护的目前最大profit，如果变大了则更新。同时比较当前值是否小于buyprice，小则更新。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        int buyPrice=prices[0],profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>buyPrice)profit=max(profit,prices[i]-buyPrice);
            if(buyPrice>prices[i])buyPrice=prices[i];
        }
        return profit;

    }
};
```