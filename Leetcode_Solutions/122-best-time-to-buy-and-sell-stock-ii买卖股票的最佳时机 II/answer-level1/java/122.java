### 解题思路


### 代码

```java
//参与多笔交易计算最大利润：只要两天之间上涨就买 且利润=两天股价差值 将所有利润相加
// 若两天之间利润不变或减少则不计入最终利润内
class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        for (int i = 1; i < prices.length; i++) {
            int tmp = prices[i] - prices[i - 1];  //tem表示相邻两天股票差值
            if (tmp > 0) profit += tmp;           //若tem为正值 则将其计入最终利益中
        }
        return profit;
    }
}


```