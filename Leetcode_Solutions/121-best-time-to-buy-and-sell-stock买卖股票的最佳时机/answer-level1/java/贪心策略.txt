### 解题思路
时间复杂度O(n)、空间复杂度O(1)

# 若股票利润最大，则应该让买入价格尽量低
从左向右，维护一个最小值minprice，
# 但是买入价格低，并不一定赚的多
例如：2 8 1 3 4 5
# 需要记录第i天的利润
因此当第i天的股价比历史最低的股价要大，则计算利润profile
同时***与第i-1天的利润比较大小，赚的更多则更新利润***
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int minprice = Integer.MAX_VALUE;//记录当前最低价格
        int maxprofit = 0;//记录最大利润
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minprice)//当前股票价格更低的时候记录下来
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)//股价上涨就计算利润，若利润更多
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
}
```