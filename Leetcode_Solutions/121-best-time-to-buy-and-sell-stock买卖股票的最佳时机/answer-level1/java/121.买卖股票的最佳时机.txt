### 解题思路
根据题意分析，要获得最大利润就要买入和卖出的差距时最大的（卖出-买入>=0）。

方法一：假设我们在第i天卖出股票，并且是在第i天前的历史最低买入的股票，那么我们此时的利润就是
prices[i]-minBuy，但是这个利润也并不一定就是我们想要的最大利润（因为最大利润是买入和卖出的最大差，我们不能保证这就是最大的差），所以不能仅仅满足在第i天前的历史最低买入一个条件就行了，我们还需要将每次卖出所得的利润进行比较，直到考虑完所有天数，最后留下的就是我们所要的最大利润。

方法二：可以将这个问题转化为求连续子数组的最大和问题。
![批注 2020-04-05 143614.jpg](https://pic.leetcode-cn.com/44edb46bd7a58c7b52d903f60f059b012af3d590cc7d4edb571ccb6a2ad9c554-%E6%89%B9%E6%B3%A8%202020-04-05%20143614.jpg)
我们规定线向下是利润为负，向上是利润为正。既然要找最大的利润，就是寻找在连续的某几天中，总体的利润和是最大的。因此这样就巧妙地利用求连续子数组的最大和从而求出了最大的利润。
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int minBuy=0;
        int maxProfit=0;
        for(int i=1; i < prices.length; i++){
            if(prices[minBuy]>prices[i]){
                minBuy = i;
            }
            else if(prices[i]-prices[minBuy]>maxProfit){
                maxProfit = prices[i]-prices[minBuy];
            }
        }
        return maxProfit;
    }
}
```