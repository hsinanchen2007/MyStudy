**思路：**

这道题比较容易想到的解法是一个 $O(N^3)$ 的动态规划解法。我们用 `dp[i][j]` 来表示用子数组 `arr[i:j+1]` （即数组中第 i 个元素到第 j 个元素，编号从 0 开始）构成树的最小代价，那么我们可以写出状态转移方程为：

$$dp_{ij} = min_{1 <= k < j}(dp_{ik} + dp_{kj} + max(arr[i:k]) * max(arr[k+1:j])) $$

那么，最终我们要求的结果就是 `dp[0][n - 1]`  的值。枚举过程是先枚举区间长度 `l`，再枚举起始点 `s`，根据起始点和长度算出区间终点 `s + l`，最后枚举区间中的点 `k`。

但是这道题目有更简单的解法。下面简述一下来自于 [lee215](https://leetcode.com/lee215/) 的思路，时间复杂度为 $O(N)$ 。这道题可以看做如下过程：在数组 `arr` 中，每次取相邻的两个数 `a` 和 `b`，然后去掉其中较小的一个，花费代价为 `a * b`，求最终将数组消减为一个元素的最小代价。那么，要想获得最小代价，我们应该采取的策略是：对于数组中的某一个数 `a`，分别向左和向右查询比它大的第一个数，在这两个数中选择较小的那个数把它消去，花费的代价最小。这个过程我们可以用单调栈来一次遍历解决掉。


**代码：**

动态规划：

```python
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        # 初始值设为最大
        dp = [[float('inf') for _ in range(n)] for _ in range(n)]
        # 初始区间查询最大值设为0
        maxval = [[0 for _ in range(n)] for _ in range(n)]
        # 求区间[i, j]中最大元素
        for i in range(n):
            for j in range(i, n):
                maxval[i][j] = max(arr[i:j + 1])
        # 叶子结点不参与计算
        for i in range(n):
            dp[i][i] = 0
        # 枚举区间长度
        for l in range(1, n):
            # 枚举区间起始点
            for s in range(n - l):
                # 枚举划分两棵子树
                for k in range(s, s + l):
                    dp[s][s + l] = min(dp[s][s + l], dp[s][k] + dp[k + 1][s + l] + maxval[s][k] * maxval[k + 1][s + l])
        return dp[0][n - 1]
```

单调栈：

```python
class Solution:
    def mctFromLeafValues(self, A: List[int]) -> int:
        res, n = 0, len(A)
        stack = [float('inf')]
        for a in A:
            while stack[-1] <= a:
                mid = stack.pop()
                res += mid * min(stack[-1], a)
            stack.append(a)
        while len(stack) > 2:
            res += stack.pop() * stack[-1]
        return res
```