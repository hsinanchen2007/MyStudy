### 启发思路
> 根据 122 题 [https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/) 的思路写的
![dp1.png](https://pic.leetcode-cn.com/caa4140f1e2b9629a63e8d238e8bb35f5cd62f0c537ab989b3084762f4fb5396-dp1.png)
![dp2.png](https://pic.leetcode-cn.com/c3c558943882f9609b4fae00ad534d1438c1708abb322a463ee520f18be3f07b-dp2.png)


### 本题思路
`profit[i][stat]`： 表示在第`i`天，状态为 `stat` 的时候所能获得的最大收益。

`stat` 有3种情况
* `0`: 未持有股票，可以买入
* `1`: 已经持有股票，可以卖出
* `2`: 刚卖出股票，正处于冷冻期，无法操作

状态转移方程为：
```
profit[i][0] = max(profit[i-1][0], // 不操作
                   profit[i-1][2] // 解除冷冻期 
                )；
profit[i][1] = max(profit[i-1][1], //继续持有股票
                   profit[i-1][0] - prices[i] // 买入股票
                )；
profit[i][2] = max(0, 
                   profit[i-1][1] + prices[i] // 卖出股票
                )；
```

初始化条件为：
```
profit[0][0] = 0; // 一直未持有
profit[0][1] = - prices[0]; // 买入
profit[0][2] = 0; // 一直未持有
```

- 时间复杂度为 $O(N * stat)$
- 空间负责度为 $O(N * stat)$

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;
        // 在第i天所能获得的最大收益
        // profit[][0]: 表示未持有股票
        // profit[][1]: 表示持有股票
        // profit[][2]: 表示冷冻期
        int[][] profits = new int[prices.length][3];

        // 初始化
        profits[0][0] = 0;
        profits[0][1] = - prices[0];
        profits[0][2] = 0;

        for (int i = 1; i < prices.length; ++i) {
            profits[i][0] = Math.max(profits[i-1][0], // 不操作
                                profits[i-1][2] // 解除冷冻期
                            );
            profits[i][1] = Math.max(profits[i-1][1], // 继续持有股票
                                profits[i-1][0] - prices[i] // 买入股票
                                );
            profits[i][2] = Math.max(0,
                                profits[i-1][1] + prices[i] // 卖出股票
                            );
        }
        return Math.max(profits[prices.length-1][0], profits[prices.length-1][2]);
    }
}
```