
这里提供两种解题思路，“迭代模拟”和详细的“动态规划”思路。



#### 迭代模拟

要求获利最大，在买入的时候我们每次都选择价格最小的时间，作为买入时间。然后在买入后的每一天都卖出去，并求一下利润，最后取这些利润之间最大的一个即可。具体算法如下：

- 定义变量 $price$，表示买入价格
  - 买入规则： $price = min(price, prices[i])$
- 定义变量$profit$，表示卖出时的利润
  - 卖出规则：$profit = max(profit, prices[i] - price)$
- 遍历所有的时间，执行上述操作，最后得到的利润 $profit$ 就是最大利润了。



#### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int price = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            price = min(price, prices[i]);
            profit = max(profit, prices[i] - price);
        }
        return profit;
    }
};
```



#### 动态规划

使用动态规划算法之前，一般都需要先解决两个问题：

- 定义何种数组来表示各个阶段的状态

- 如何通过前阶段已有的状态，推出现阶段的状态



在这道题，我们定义一个二维数组 $dp[n][2]$ 来表示 $n$ 个阶段的状态。

$dp[i][0]$ 表示**前** $i$ 天，没有持有股票状态下的大利润

- 转移方程：$dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])$

$dp[i][1]$ 表示**前** $i$ 天，持有股票状态下的最大利润

- 转移方程：$dp[i][1] = max(dp[i-1][1], 0 - price[i])$

而我们需要的答案就是，前 $n$ 天没有持有股票状态下的最大利润：$dp[n][0]$



你可能注意到，第二个状态转移方程，正常来讲应该写成：$dp[i][1] = max(dp[i-1][1], dp[i][0] - price[i])$ ，但上面 $max$ 的第二个参数却是 $0 - price[i]$ 。

这是因为题目要求股票只能买卖一次，$0$ 表示未进行股票交易时的初始金额，而 $dp[i-1][0]$ 表示前 $i - 1$ 天未持有股票状态下的最大利润，但前 $i - 1$ 天可能完成了多次股票交易，所以不满足条件。



#### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int dp[200010][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], 0 - prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};
```



#### 优化动态规划

通过状态转移方程，我们可以看出，现阶段状态只和前一阶段的状态有关，因此我们并不需要定义数组来记录每一个阶段的状态。

相反，我们只需要定义两个变量，分别来表示前一天持有股票，或未持有股票状态下的最大利润，然后不断迭代更新这俩变量即可。



#### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_0 = 0, cur_1 = INT_MIN;
        for (int i = 0; i < prices.size(); i ++) {
            cur_0 = max(cur_0, cur_1 + prices[i]);
            cur_1 = max(cur_1, 0 - prices[i]);
        }
        return cur_0;
    }
};
```



#### 最后

感谢您的观看！欢迎大家留言，一起讨论交流，共同进步。

至此，您已经掌握了使用模拟迭代和动态规划解决此题的基本步骤，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢您的支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)