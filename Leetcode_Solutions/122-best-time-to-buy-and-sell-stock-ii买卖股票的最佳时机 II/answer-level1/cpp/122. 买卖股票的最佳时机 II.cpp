## 模拟法
**1. 假设已经买了第一天的股票
2. 从第一天开始判断
3. 如果价格第二天会降，当天卖掉，买第二天的
4. 最后全部卖掉**

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==0) return 0;
        int ans=-prices[0]; //假设已经买了第一天的股票
        for(int i=0; i<len-1; i++){ //从第一天开始判断
            //如果价格第二天会降，果断卖掉，买第二天的
            if(prices[i] > prices[i+1]){
                ans += prices[i]-prices[i+1]; //净赚prices[i]-prices[i+1]
            }
        }
        return ans + prices[len-1]; //最后全部卖掉
    }
};
```