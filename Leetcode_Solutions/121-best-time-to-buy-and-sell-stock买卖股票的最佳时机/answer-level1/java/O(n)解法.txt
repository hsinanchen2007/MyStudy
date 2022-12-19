### 解题思路
此处撰写解题思路
使用定义两个值：
    1、最大收益
    2、历史最低价格，第一天的最低价格定义为第一天的价格
解题思路：
    1、不断变化历史最低价格，如果存在比历史更低的价格，则覆盖历史最低价格
    2、一次循环遍历，通过今日价格和历史最低价格做减法运算，得到今日股票收益
    3、通过今日股票收益和历史最大股票收益做对比，如果今日比历史股票收益高，则抛售股票，更新历史最大股票收益
    

### 代码

```java
class Solution {
    public  int maxProfit(int[] prices) {
        int maxMoney = 0;
        int lowPrice = prices.length > 0 ? prices[0] : 0;
        for (int i = 0; i < prices.length; i++) {

            if (prices[i] < lowPrice) {
                lowPrice = prices[i];
            }
            int currentMaxMoney = prices[i] - lowPrice;
            if (currentMaxMoney > maxMoney) {
                maxMoney = currentMaxMoney;
            }
        }
        return maxMoney;
    }
}
```