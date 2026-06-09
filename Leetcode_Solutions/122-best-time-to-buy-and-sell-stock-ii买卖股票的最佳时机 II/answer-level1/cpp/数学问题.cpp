### 解题思路
只要第二天的价格高于第一天的价格就第一天买第二天卖。
题目没让算哪些天持有股票，用不到动态规划、贪心算法。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int profit = 0;
        for(int i=0;i<prices.size()-1;++i) if(prices[i+1]>prices[i]) profit+=prices[i+1]-prices[i];
        return profit;
    }
};
```