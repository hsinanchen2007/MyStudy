### 解题思路

- 设定，dp[i][j]表示以(i,j)为右下角坐标的正方形的边长；
- dp[i][j]的取值，取决于它左边，上边，及左上角的位置处，是否有边长大于等于1的正方形存在；
  - 假如dp[i][j-1], dp[i-1][j], dp[i-1][j-1]，有一个位置的边长为0，那么dp[i][j]的正方形边长均不能向左上扩展；
  - 假如左边，上边，左上角位置处的正方形边长均大于等于1，那么为了满足正方形的等变长，我们只能取其中最短的边长，作为扩展的边长，即让其中的最短边长+1，即为当前位置能够形成的正方形的边长；
- 按照上述思路，只需要从(1,1)位置开始遍历即可；
- 需要注意的是，第一行与第一列中，凡是出现1的位置，其正方形边长均为1；
- 网格中，凡是为0的地方，其正方形边长均为0；

### 代码

```python3
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows = len(matrix)
        if rows == 0:
            return 0
        cols = len(matrix[0])

        dp = [[0]*cols for _ in range(rows)]

        rst = 0
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == '1':
                    dp[i][j] = 1
                    rst = 1

        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][j] == '0':
                    continue
                tmp = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])
                if tmp < 1:
                    continue
                dp[i][j] = tmp + 1
                rst = max(rst, dp[i][j])

        return rst*rst
        pass
```