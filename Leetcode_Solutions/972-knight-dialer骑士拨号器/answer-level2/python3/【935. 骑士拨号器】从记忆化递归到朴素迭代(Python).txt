# 深度优先遍历（DFS）

## 思路

这道题要求解一个数字。并且每一个格子能够跳的状态是确定的。 因此我们的思路就是“状态机”（动态规划），暴力遍历（BFS or DFS），这里我们使用DFS。（注意这几种思路并无本质不同）

对于每一个号码键盘，我们可以转移的状态是确定的，我们做一个”预处理“，将这些状态转移记录到一个数组jump，其中jump[i] 表示i位置可以跳的点（用一个数组来表示）。问题转化为：

- 从0开始所有的路径
- 从1开始所有的路径
- 从2开始所有的路径
- ...
- 从9开始所有的路径

不管从几开始思路都是一样的。 我们使用一个函数f(i, n)表示`骑士在i的位置，还剩下N步可以走`的时候可以拨出的总的号码数。那么问题就是求解 `f(0, N) + f(1, N) + f(2, N) + ... + f(9, N)`。对于 f(i, n)，我们初始化cnt 为0，由于i 能跳的格子是 jump[i]，我们将其 `cnt += f(j, n - 1)`，其中j 属于 jump[i]，最终返回cnt即可。

不难看出，这种算法有大量重复计算，我们使用记忆化递归形式来减少重复计算。 这种算法勉强通过。

## 代码

```python
class Solution:
    def knightDialer(self, N: int) -> int:
        cnt = 0
        jump = [[4, 6], [6, 8], [7, 9], [4, 8], [
            0, 3, 9], [], [0, 1, 7], [2, 6], [1, 3], [2, 4]]
        visited = dict()

        def helper(i, n):
            if (i, n) in visited: return visited[(i, n)]
            if n == 1:
                return 1
            cnt = 0
            for j in jump[i]:
                cnt += helper(j, n - 1)
            visited[(i, n)] = cnt
            return cnt
        for i in range(10):
            cnt += helper(i, N)
        return cnt % (10**9 + 7)
```

**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

# 朴素遍历

## 思路

我们使用迭代的形式来优化上述过程。我们初始化十个变量分别表示键盘不同位置能够拨出的号码数，并且初始化为1。接下来我们只要循环N - 1次，不断更新状态即可。不过这种算法和上述算法并无本质不同。

## 代码

```python
class Solution:
    def knightDialer(self, N: int) -> int:
        a0 = a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = a9 = 1
        for _ in range(N - 1):
            a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 = a4 + a6, a6 + a8, a7 + \
                a9, a4 + a8, a0 + a3 + a9, 0, a0 + a1 + a7, a2 + a6, a1 + a3, a2 + a4
        return (a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9) % (10**9 + 7)
```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
