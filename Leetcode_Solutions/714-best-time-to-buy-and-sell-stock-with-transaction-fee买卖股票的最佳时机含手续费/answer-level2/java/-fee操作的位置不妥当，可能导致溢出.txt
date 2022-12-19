### 解题思路
该思路的-fee操作不可以随意添加，
理论上两个地方进行扣除fee的操作应该都可以，分别是
在前一天是持有的，今天是卖出的，导致今天持仓为0.我在卖出股票的时候扣除交易费即
dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]-fee);
第二个是，前一天是空仓，今天我买了股票，我在买股票的时候，扣除交易费即下述代码的情形：
dp_i_1 = Math.max(dp_i_1, tmp - prices[i] -fee);

但是实际上第一种，在卖出股票的时候扣除费用会导致移除，因为dp_i_1的base case的值定位了负无穷，如果此时再扣除fee，那么就会溢出，出错。

本题的思路可以参见https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/tuan-mie-gu-piao-wen-ti
这个大佬说的真好！！！
### 代码

```java
class Solution {
    public int maxProfit(int[] prices, int fee) {
        if(prices==null || prices.length==0) {
            return 0;
        }
        int n = prices.length;
        int dp_i_0 = 0;
        int dp_i_1 = Integer.MIN_VALUE;
        for(int i=0; i<n; i++) {
            int tmp = dp_i_0;
            dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = Math.max(dp_i_1, tmp - prices[i] -fee);
        }
        return dp_i_0;
    }
}
```