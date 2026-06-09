### 说明
股票问题一共有六道：买卖股票的最佳时机（[1](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/gu-piao-wen-ti-python3-c-by-z1m/)，[2](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)，3，[4](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)）、[含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)、[含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)。本题是第三道，属于较难题目。
### 思路一：划分
由于进行两次交易，我们只需找到一个分界点 $i$，$1...i-1$ 天内进行第一次交易，$i...n$ 内进行第二次交易：

$$\underbrace{|--------} |  \underbrace{-------|}$$
$$第 \ 1...i-1 \ 天 \ \ \ \ \ \ \ \ \ \ \  \  \ \ 第 \ i...n \ 天$$

因此我们分别使用 $f(i)$ 和 $g(i)$ 保存两段的最大利润，最后计算两段和的最大值。对于每一段的利润，按照 [股票问题一思路2](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/gu-piao-wen-ti-python3-c-by-z1m/) 计算即可。

#### 代码
```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0

        n = len(prices)
        f = [0 for _ in range(n)] # 保存第i天最大利润
        g = [0 for _ in range(n)] 
        # 计算 1 ~ i 
        minprice = prices[0]
        for i in range(1, n): 
            f[i] = max(f[i - 1], prices[i] - minprice) # 完整交易出现在前 i-1 天里，或者第i天
            minprice = min(minprice, prices[i])
            

        # 计算 i ~ n，倒序遍历
        maxprice = prices[n - 1]
        for j in range(n - 2, -1, -1):
            g[j] = max(g[j + 1], maxprice - prices[j])  # 完整交易出现在 j 之后几天里，或者第j天
            maxprice = max(maxprice, prices[j])

        # 取两次交易的最大值
        res = max(f[n - 1], g[0]) # 交易一次
        for i in range(1, n - 2):
            res = max(f[i] + g[i + 1], res)
        return res
```
#### 复杂度分析
- 时间复杂度：$O(n)$。
- 空间复杂度：$O(n)$。
### 思路二：动态规划
思考一个状态方程，大致分三步：
- 状态表示
- 状态属性
- 状态计算

*1. 状态表示*
很容易想到，可用 $dp(i,j)$ 表示第 $i$ 天进行 $j$ 次交易的最大利润。（如果没想到，多做做题就有经验了）

*2. 状态属性*
可以看到题目要求是最大利润，所以属性就是求一个最大值。

*3. 状态计算*
这个是最难的一步，方法就是从 $dp(i, j)$ 表示的 **实际意义** 出发，尽可能地划分出所有的条件。

比如本题，我们从关键词第 $i$ 天，第 $j$ 次交易进行思考，不难发现第 $i$ 天可以划分两种情况：

- 不交易：第 $i$ 天什么都没发生，交易次数 $j$ 不变，利润为前一天的利润：
$$dp(i, j)=dp(i - 1,j)$$
- 交易：利润为前 $j - 1$ 次交易的利润与第 $i$ 天交易的利润之和：
$$dp(i, j)=\underbrace{dp(k-1,j-1)} +\underbrace{prices(i)-prices(k)}$$
$$第 \ 1...k-1 \ 天 \ \ \ \ \ \ \ \ \ \ \ \ \ 第 \ k...i \ 天$$

由于买入卖出为一次交易，因此准确来讲如果在第 $i$ 天进行交易就是指在第 $i$ 天进行卖出操作，那么是何时买入的呢？如果买入为第 $k$ 天，则 $k$ 满足 $k\in[1,...,i]$。

#### 算法

由于重复计算 $k$ 会多嵌套一层循环导致代码超时，因此需要将第一笔交易获得的利润整合到第二笔交易的成本中。

$$dp(i, j)=\underbrace{prices(i)} -\underbrace{(prices(k)-dp(k-1,j-1))}$$
$$\ \ \ \ \ \ \ \ \ \ 第 \ i \ 天卖出价格 \ \ \ \ \ 第 \ k\ 天买入价格 - 第 1 次交易利润$$


#### 代码

```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        row, col = len(prices), 3
        dp = [[0 for _ in range(col)] for _ in range(row)]
        for j in range(1, 3):
            mincost = prices[0] # 初始化成本为第一天的价格
            for i in range(1, row):
                mincost = min(mincost, prices[i] - dp[i - 1][j - 1]) # 买-利润=卖之前的成本
                dp[i][j] = max(dp[i - 1][j], prices[i] - mincost)
        return dp[row - 1][2]
```

```python(超时) []
class Solution:
    """原始思路的代码"""
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        row, col = len(prices), 3
        dp = [[0 for _ in range(col)] for _ in range(row)]
        for j in range(1, 3):
            for i in range(1, row):
                mincost = prices[0]
                for k in range(1, i + 1): # 与上一层循环相同
                    minpcost = min(mincost, prices[k] - dp[k - 1][j - 1])
                dp[i][j] = max(dp[i - 1][j], prices[i] - mincost)
        return dp[row - 1][2]
```


#### 复杂度分析
- 时间复杂度：$O(2n)$。
- 空间复杂度：$O(3n)$。

思路上有任何问题欢迎讨论~

![白色背景关注.jpg](https://pic.leetcode-cn.com/6c18bb76abad971a2db54a010561f44fd1445ca10f9b671ecfee1a7df2482c08-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
