### 解题思路
首先将矩阵进行转置，然后按照中间线进行左右对称交换即可。python代码如下：

执行用时 :40 ms, 在所有 Python3 提交中击败了61.50%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了100.00%的用户
### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        mid = n >> 1
        for i in range(n):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        for i in range(n):
            for j in range(mid):
                matrix[i][j], matrix[i][n - 1 - j] = matrix[i][n - 1 - j], matrix[i][j]


实际上，在第一次进行转置时，第i行第数据已经完成，此时可以直接进行左右交换，减少一次for循环。
执行用时 :36 ms, 在所有 Python3 提交中击败了80.33%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了100.00%的用户
### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        mid = n >> 1
        for i in range(n):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
            for j in range(mid):
                matrix[i][j], matrix[i][n - 1 - j] = matrix[i][n - 1 - j], matrix[i][j]

```