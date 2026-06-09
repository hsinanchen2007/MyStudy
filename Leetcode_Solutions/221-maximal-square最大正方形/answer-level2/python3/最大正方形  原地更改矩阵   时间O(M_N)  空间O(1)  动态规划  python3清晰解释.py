### 解题思路
动态规划解题一般需要先构建一个dp数组
根据LeetCode官方解可以知道此问题的状态转移方程为：`dp[i][j]=min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])+1`，其中dp数组用来存储以第i行第j列元素为右下角的最大正方形的边长
由于输入的矩阵为0-1矩阵，所以输入矩阵可以直接作为我们需要的dp数组，在遍历输入矩阵时可以按照上述状态转移公式原地更改矩阵

遍历了一遍矩阵，所以：
**时间复杂度：O(M*N)**

常量的新存储空间，所以：
**空间复杂度：O(1)**

**注意：由于输入矩阵中的元素都是字符型，所有要在遍历过程中转化成整形以方便计算；如果遍历到了第0行或者第0列，不需要使用状态转移方程**

### 代码

```python3
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        res = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == '1':
                    matrix[i][j] = 1
                    if i == 0 or j == 0:
                        res = max(matrix[i][j], res)
                    else:
                        matrix[i][j] = min(matrix[i-1][j], matrix[i-1][j-1], matrix[i][j-1])+1
                        res = max(matrix[i][j], res)
                else:
                    matrix[i][j] = 0
        return res**2

```