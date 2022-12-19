### 解题思路
采用动态规划的思路，dp_i_0代表的是当日没有持股，dp_i_1代表的是当日持股
- 某一天没有持股的状态，可能是前一天也没有持股，也可能是前天持股了，今天卖出了；
- 某一天持股的状态，因为只能买卖一次，所以可能前一天也持股了，或者就是今天刚买入的股票；
确定这两个状态，即可确定对应的值即可；
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        //dp_i_0代表的是当日没有持股，dp_i_1代表的是当日持股
        int dp_i_0 = 0,dp_i_1 = Integer.MIN_VALUE;
        for(int i=0;i<prices.length;i++){
            dp_i_0 = Math.max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1 = Math.max(dp_i_1,-prices[i]);
        }
        return dp_i_0;
    }
}
```