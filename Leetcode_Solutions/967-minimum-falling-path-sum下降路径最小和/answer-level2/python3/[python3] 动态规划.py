# 方法1: 暴力法

通过深度优先搜索, 记录全部下降路径的路径和, 取最小值, 可以通过剪枝来提高一点点速度, 就是DFS递归时, 可以判断一下当前的最小路径和, 如果当前路径和已经超过了最小路径和, 就直接终止递归了.

# 方法2: 动态规划

自底向上递归, 通过动态规划的方式得到结果. 

* 状态定义`DP[i][j]`: 自底向上时, 位于数组中(i, j)的最小路径和
* 状态转移方程: `DP[i][j] = min(DP[i+1][j-1], DP[i+1][j], DP[j+1]) + A[i][j]`

可以看到, DP数组只需要定义一个 `2 * n` 的二维数组即可, 其中 `n` 是方形数组的行数, 这里好像不能通过一维数组实现, 因为状态转移方程中可以看到一个位于 `0 < j < n-1` 的 DP 值会被用到至少两次, 所以无法直接覆盖下一层的结果.

```python
class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        size = len(A)
        DP = [[0 for _ in range(size)]] * 2
        DP[(size-1)%2] = A[-1]
        i = size - 2
        while i >= 0:
            x, y = i % 2, (i+1) % 2
            for j in range(size):
                if j == 0:
                    DP[x][j] = min(DP[y][0], DP[y][j+1]) + A[i][j]
                elif j == size-1:
                    DP[x][j] = min(DP[y][j-1], DP[y][j]) + A[i][j]
                else:
                    DP[x][j] = min(DP[y][j-1], DP[y][j], DP[y][j+1]) + A[i][j]
            i -= 1
        return min(DP[0])
```