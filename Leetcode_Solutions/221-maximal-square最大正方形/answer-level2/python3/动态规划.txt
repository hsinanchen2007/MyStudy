## 思路:

动态规划

`dp[i][j]`代表以 `i,j`为正方形右下角的最大边长是多少？

动态方程：

在 `matrix[i][j] == "1"`，情况下

​	`dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1`

为了求解方便，构造多一个长度的二维数组！

```python
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        row = len(matrix)
        col = len(matrix[0])
        dp = [[0] * (col + 1) for _ in range(row + 1)]
        res = 0
        for i in range(1, row +1):
            for j in range(1, col + 1):
                if matrix[i - 1][j - 1] == "1":
                    dp[i][j] = min(dp[i-1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
                    res = max(res, dp[i][j] ** 2)
        return res
```

------



下面有几种超时算法(最后一个过不了)， 但是思想可以借鉴！

主要思想就是，求出`dp[i][j]`表示前`i`行，前`j`列所有`1`的个数

那么以`i,j`为右下角形成的矩形就是等于 `dp[i][j] - dp[k][j] - dp[i][j - i + k] + dp[k][j - i + k]`

这里的 `k` 表示小于 `i` 的行.

```python
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0	
    	row = len(matrix)
        col = len(matrix[0])
        dp = [[0] * (col + 1) for _ in range(row + 1)]
        for i in range(1, row + 1):
            for j in range(1, col + 1):
                dp[i][j] = int(matrix[i - 1][j - 1]) + dp[i][j - 1]
        # pprint(dp)
        for j in range(1, col + 1):
            for i in range(1, row + 1):
                dp[i][j] = dp[i - 1][j] + dp[i][j]
        # 思路一 
        # res = 0
        # for i in range(1, row + 1):
        #     for j in range(1, col + 1):
        #         for k in range(0, i):
        #             if j - i + k >= 0 and (i - k) ** 2 == dp[i][j] - dp[k][j] - dp[i][j - i + k] + dp[k][j - i + k]:
        #                 res = max(res, (i - k) ** 2)
        # return res
        # 思路二 卷积里滑动窗口的感觉
        max_edge = min(row, col)
        res = 0
        while max_edge:
            for i in range(row - max_edge + 1):
                for j in range(col - max_edge + 1):
                    if max_edge ** 2 == dp[i + max_edge][j + max_edge] - dp[i+max_edge][j] - dp[i][j + max_edge] + dp[i][j]:
                        return max_edge ** 2
            max_edge -= 1
        return res
```

