### 解题思路
动态规划：
- sell表示当前最后操作为卖出股票时的最大盈利
- hold表示当前最后操作为持有股票时的最大盈利

状态转移方程：
- hold=max(hold,sell-prices[i])
- sell=max(sell,hold+prices[i])
顺序可以颠倒

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int sell=0,hold=-prices[0];
        for(int i=1;i<prices.size();i++){
            hold=max(hold,sell-prices[i]);
            sell=max(sell,hold+prices[i]);
        }
        return sell;
    }
};
```