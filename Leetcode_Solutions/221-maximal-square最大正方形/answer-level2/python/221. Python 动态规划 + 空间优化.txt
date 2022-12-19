### 解题思路
思路可以看官方题解的思路，这里就不重复了，想重新定义一下自己理解的dp[i][j]的意义：**以(i, j)为右下角的最大正方形的边长**，转移方程是dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j])，从转移方程可以发现当前的状态只和三个状态有关，所以对于dp数组我们可以只保存两行即可。
trick: 每行多加了一个0填充，防止第一个元素出现错误。

### 代码

```python
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if matrix == []:
            return 0
        len_1 = len(matrix)
        len_2 = len(matrix[0])
        dp = [[0] * (len_2 + 1) for _ in range(2)] # dp[i][j]记录以(i, j)为右下角的最大正方形边长
        max_len = 0
        for i in range(len_1):
            for j in range(len_2):
                if matrix[i][j] == '0':
                    dp[i % 2][j + 1] = 0
                else:
                    temp = min(dp[i % 2][j],
                               dp[(i - 1) % 2][j],
                               dp[(i - 1) % 2][j + 1]) + 1
                    dp[i % 2][j + 1] = temp
                    if temp > max_len:
                        max_len = temp
        return max_len ** 2
```