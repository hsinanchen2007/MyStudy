![image.png](https://pic.leetcode-cn.com/422353488488e89d46f2040eab8e13a8c5dfc5acd05725d1dd30c03448b11e2b-image.png)

### 解题思路
1、一次提交就过了，感觉没有绕的地方，直接写就完事了；
2、假如当天比前一天的价格低，那么肯定在当天买进；
3、假如当天比前一天的价格高，那就可以考虑卖出，算出利润，存起来，然后再不断比较每天和前一天的价格，更新最高利润，直到最后。

###代码思路
1、变量buy是买进的时机，变量profit是不断更新的最高利润，初值为0，避免题例的第二种情况下无法更新利润；
2、从第二天开始遍历，假如当天比前一天价格低，那么更新buy，即当天买进；
3、假如当天比前一天价格高，那么在判断在当天卖出是否会获得更高的利润，有，则更新profit。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 1;
        int profit = 0;

        for(int i = 2; i <= prices.size(); i++){
            if(prices[i-1] < prices[buy-1]) buy = i;
            else{
                if(prices[i-1] - prices[buy-1] > profit) profit = prices[i-1] - prices[buy-1];
            }
        }
        return profit;
    }
};
```