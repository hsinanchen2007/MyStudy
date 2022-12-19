> 首先使用群举法

超时了!!!

```
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        self.res_s = float("inf")
        def dp(triangle, i, depth, s, path):
            if depth >= len(triangle):
                self.res_s = min(self.res_s, s)
                return
            for j in [i, i + 1]:
                dp(triangle, j, depth + 1, s + triangle[depth][i], path + [triangle[depth][i]])
            
        dp(triangle, 0, 0, 0, [])
        return self.res_s
```
> 优化1：

使用动态规划：一般用深度优先遍历解决的问题，可以用动态规划优化！

记：三角形的高度为depth（0 <= depth < len(triangle)），每一层的元素用triangle[depth][i]进行索引。

如例子所示，从depth=0走到depth=3，共需要走4步，每一步可能的元素的小标的小标为：0 <= i < len(triangle[depth]) 。

定义状态：dp[depth][i]来表示走到depth步(层)第i个位置时，最小路径的和。

状态转移方程为:dp[depth][i] = min(dp[depth - 1][i], dp[depth - 1][i - 1]) （与第depth层第i个位置相邻的上一层元素是: i, i - 1）
```
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if len(triangle) <= 0:
            return 0
        dp = [[float("inf") for _ in range(len(triangle[i]))] for i in range(len(triangle))]
        dp[0][0] = triangle[0][0]
        for depth in range(1, len(dp)):
            for i in range(len(dp[depth])):
                if i < len(triangle[depth - 1]):
                    dp[depth][i] = min(dp[depth][i], dp[depth - 1][i] + triangle[depth][i])
                if i - 1 >= 0 :
                    dp[depth][i] = min(dp[depth][i], dp[depth - 1][i - 1] + triangle[depth][i])
        return min(dp[-1])
```

> 优化2：


空间优化，在计算depth层的时候，仅用到depth - 1层的信息，故在存储的时候，只需要建立2 * len(triangle) 大小的二维矩阵即可！

```
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if len(triangle) <= 0:
            return 0
        dp = [[float("inf") for _ in range(len(triangle))] for _ in range(2)]
        dp[0][0] = triangle[0][0]
        for depth in range(1, len(triangle)):
            for i in range(len(triangle[depth])):
                val = float("inf")    
                if i < len(triangle[depth - 1]):
                    val = min(val, dp[(depth - 1) % 2][i] + triangle[depth][i])
                if i - 1 >= 0 :
                    val = min(val, dp[(depth - 1) % 2][i - 1] + triangle[depth][i])
                dp[depth % 2][i] = val
        return min(dp[(len(triangle) - 1) % 2])
```
