### 解题思路
因为此题不限制买卖次数，但同时只可以买卖一笔彩票。即，将之前的彩票卖了以后才可以买彩票。
使用可以对数组进行一次扫描，扫描到位置i的时候，当prices[i]>prices[i-1]时即可以卖出彩票，利润为
prices[i]-prices[i-1]；当prices[i]<prices[i-1]时可以认为之前的彩票已经结束可以进行购买新的彩票。
只要在涨，就赚下差值，只要跌了，就重新开始。所以一旦我们在扫描的时候发现当前值就变小了，就开始重新算差值。
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int amount=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
            amount+=prices[i]-prices[i-1];
        }
        return amount;
        
    }
};
```