
# 常规动态规划



## 思路

本题和[爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/solution/70-pa-lou-ti-cong-onkong-jian-dao-o1kong-jian-pyth/) 题目条件一样，只不过那道题是求`多少种不同的方法`，本题是求解最小能量。 其实原理是一样的，我把它定义为“换汤不换药”。


转移方程很简单`dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i - 2]`。我们i从2开始，并且初始化dp[i]全部为0即可。唯一需要注意的是，我们最终求解的应该是`dp[-1]`和`dp[-2]`的较小值。 因为正如题目所说，你可以在-1的时候走一步，也可以-2的时候走两步，因此我们选较小值即可。



## 代码



```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0] * (n + 2)
        for i in range(2, n + 2):
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i - 2]
        return min(dp[-1], dp[-2])
```

**复杂度分析**
- 时间复杂度：$O(N)$，其中N为楼梯长度。
- 空间复杂度：$O(N)$，其中N为楼梯长度。


# 优化空间

## 思路

前面说了，我们的转移方程为`dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i - 2]`，那么容易看出其实dp[i]之和前两个元素有关。这是一个空间优化的信号，相当于告诉我们`用两个变量记录一下就可以`。包括上面提到的爬楼梯也是一样，也可以采取类似的策略减少空间复杂度。 类似的套路在动态规划问题中很多。

## 代码


```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        a = b = 0
        for i in range(len(cost)):
            a, b = b, min(a, b) + cost[i]
        return min(a, b)
```
**复杂度分析**
- 时间复杂度：$O(N)$，其中N为楼梯长度。
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)