# 递归法 (超时)
我们定义问题为f(n)，那么由题目信息可知，f(n) = f(n - 1) + f(n - 2)。递归的终止条件为n 为 1的时候，我们返回1,n为2的时候我们返回2.

> 你可以使用记忆化递归优化运行时间

代码:

```python
class Solution:
    def numWays(self, n: int) -> int:
        if n <= 1:
            return 1
        if n == 2:
            return 2
        cnt = 0
        cnt += self.numWays(n - 1) + self.numWays(n - 2)
        return cnt % 1000000007
```

**复杂度分析**

- 时间复杂度：我们可以想象成组合，由排列组合原理知道组合数为2^(n)，故时间复杂度为 $O(2^(n))$
- 空间复杂度：空间复杂度取决于栈深度，因此空间复杂度 $O(2^(n))$

# 数学法

我们可以使用动态规划（DP），但是其实我们发现递推公式中“当前项只和前两项有关”，于是我们使用两个数字a和b来表示DP中的最近两项，其余部分和DP相同

代码:

```python
class Solution:
    def numWays(self, n: int) -> int:
        a, b = 1, 1
        for _ in range(n):
            a, b = b, a + b
        return a % 1000000007
```

**复杂度分析**

- 时间复杂度：$O(n)$
- 空间复杂度: $O(1)$


欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)