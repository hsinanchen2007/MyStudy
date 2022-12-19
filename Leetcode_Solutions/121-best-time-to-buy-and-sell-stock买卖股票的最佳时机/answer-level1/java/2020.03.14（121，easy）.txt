### 解题思路
本题使用**贪心算法**买卖股票，思想就是**以最低的价格买入，以最高的价格售出！**

定义一个min用来记录股票的最小值。通过遍历数组，如果之后有一天比之前买入价格更低，则将最低购买价格赋值给min

定义一个max用来记录股票售出和买入之间的最大差额，即用当前价格减去最小值所得的差值。

每当遇到更高的价格就用他减去最小值并与之前的最大差值进行比较，差额最大的即为所求最大利润。
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int max= 0;
        int n = prices.length;
        for(int i = 0 ; i < n ; i++){
            if(prices[i] < min){//遍历完整个数组就会选出最小值
                min = prices[i];
            }else if(prices[i] - min > max){//依次比较，选出最大差值
                max = prices[i] - min;
            }
        }
        return max;
    }
}
```