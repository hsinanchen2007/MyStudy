#### 解题思路：

以下按照动态规划流程解题。

##### 动态规划解析：

- **状态定义：** 设动态规划列表 $dp$ ，$dp[i]$ 代表以 $prices[i]$ 为结尾的子数组的最大利润（以下简称为 “前 $i$ 日的最大利润” 。
- **转移方程：** 由于题目限定 “买卖该股票一次” ，因此前 $i$ 日最大利润 $dp[i]$ 等于前 $i - 1$ 日最大利润 $dp[i-1]$ 和第 $i$ 日卖出的最大利润中的最大值。

$$
前 i 日最大利润 = \max(前 (i-1) 日最大利润, 第 i 日价格 - 前 i 日最低价格)
$$

$$
dp[i] = \max(dp[i - 1], prices[i] - \min(prices[0:i]))
$$

- **初始状态：** $dp[0] = 0$ ，即首日利润为 $0$ ；
- **返回值：** $dp[n - 1]$ ，其中 $n$ 为 $dp$ 列表长度。

![Picture1.png](https://pic.leetcode-cn.com/4880911383c41712612103c612e390f1ee271e4eb921f22476836dc46aa3a58a-Picture1.png){:width=550}

##### 效率优化：

- **时间复杂度降低：** 前 $i$ 日的最低价格 $\min(prices[0:i])$ 时间复杂度为 $O(i)$ 。而在遍历 $prices$ 时，可以借助一个变量（记为成本 $cost$ ）每日更新最低价格。优化后的转移方程为：

$$
dp[i] = \max(dp[i - 1], prices[i] - \min(cost, prices[i])
$$

- **空间复杂度降低：** 由于 $dp[i]$ 只与 $dp[i - 1]$ , $prices[i]$ , $cost$ 相关，因此可使用一个变量（记为利润 $profit$ ）代替 $dp$ 列表。优化后的转移方程为：

$$
profit = \max(profit, prices[i] - \min(cost, prices[i])
$$

##### 复杂度分析：

- **时间复杂度 $O(N)$ ：** 其中 $N$ 为 $prices$ 列表长度，动态规划需遍历 $prices$ 。
- **空间复杂度 $O(1)$ ：** 变量 $cost$ 和 $profit$ 使用常数大小的额外空间。

<![Picture2.png](https://pic.leetcode-cn.com/63c9828873e55e57aca2c317afad592a6d8ba00c433d9b0196c3db4e2f04a4e4-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/cd8a8fabe6f0a87f64789548bbd0406f12243babeec564e89546631a2cdd73a9-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/56d441e7a654f6c3c0cb33efe2bb527fdaaecccecc799b93c1f29bfb1fa998c5-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/818a376952c81779606587744461eba85786c0b1333932e58c9c062c5cfe67b2-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/7ba378da9af7489b616aec9521ac1769b3ea644b3ff18a7e411323f1fb49efd9-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/e00b79988f82af0b5fb2bcaf6dad138f88d67d046213a78298d788511df8b7fb-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/2ab7338e3d90d9c6b6bb0026b83091e7deae74e2cfb9764d9deba75cfb0c0491-Picture8.png),![Picture9.png](https://pic.leetcode-cn.com/626ef73bddeb29cb4e10982746a9922d9e0f536f4a4f6e7e48cf1764224cbadc-Picture9.png)>

#### 代码：

```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cost, profit = float("+inf"), 0
        for price in prices:
            cost = min(cost, price)
            profit = max(profit, price - cost)
        return profit
```

```java []
class Solution {
    public int maxProfit(int[] prices) {
        int cost = Integer.MAX_VALUE, profit = 0;
        for(int price : prices) {
            cost = Math.min(cost, price);
            profit = Math.max(profit, price - cost);
        }
        return profit;
    }
}
```

