1.最小路径与上一步走的路径和有关系，需要找到前一步的最小和，加上当前的数。
2.dp[i][j]，记录到矩阵的第i,j个元素，已经走的最短路径
3.dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]) 即：上一个数（左边，右边的数的最小值）加当前矩阵的数

```javascript []
console.log('Hello world!')
```
```python []
def sol(matrix):
    m = len(matrix)
    n = len(matrix[0])
    dp=[ [0 for _ in range(n)] for _ in range(m)]
    dp[0][0] = matrix[0][0]
    # 初始化dp
    for i in range(m):
        for j in range(n):
            # 第一行
            if i == 0 and j != 0:
                dp[i][j] = matrix[i][j] + dp[i][j-1]
            # 第一列
            elif i!= 0 and j == 0:
                dp[i][j] = matrix[i][j] + dp[i-1][j]
    # 下一步走的与上一步走的和 有关系
    for i in range(m):
        for j in range(n):
            if i != 0 and j != 0:
                dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1])
    return dp[-1][-1]
```
```ruby []
puts 'Hello world!'
```
