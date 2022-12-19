
# 常规动态规划



## 思路

本题和[746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/solution/746-shi-yong-zui-xiao-hua-fei-pa-lou-ti-cong-onkon/) 题目条件一样，只不过那道题是求解最小能量，本题求`多少种不同的方法`。 其实原理是一样的，我把它定义为“换汤不换药”。


转移方程很简单`dp[i] = dp[i - 1] + dp[i - 2]`。我们i从2开始，并且初始化dp[i]全部为i + 1即可(实际上只需要初始化dp[0] = 1, dp[1] = 2 即可))，最终求解的就是dp[-1]



## 代码



```python
class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [i + 1 for i in range(n)]
        for i in range(2, n):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[-1]
```

**复杂度分析**
- 时间复杂度：$O(N)$，其中N为楼梯长度。
- 空间复杂度：$O(N)$，其中N为楼梯长度。


# 优化空间

## 思路

前面说了，我们的转移方程为`dp[i] = dp[i - 1] + dp[i - 2]`，那么容易看出其实dp[i]之和前两个元素有关。这是一个空间优化的信号，相当于告诉我们`用两个变量记录一下就可以`。包括上面提到的爬楼梯也是一样，也可以采取类似的策略减少空间复杂度。 类似的套路在动态规划问题中很多。

## 代码


```python
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1: return 1
        a, b = 1, 2
        for i in range(2, n):
            a, b = b, a + b
        return b
```
**复杂度分析**
- 时间复杂度：$O(N)$，其中N为楼梯长度。
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)