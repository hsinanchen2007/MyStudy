### 解题思路
- **关键 1**：写出对于矩阵中任一个点[i, j]旋转后所在的位置[j, N-1-i]，进而写出所有四个点的位置变换。
- **关键 2**：对N的奇偶进行分类讨论，尤其是N为奇数的时候，找出所有不重复的被旋转的元素，作为位置变换时遍历的范围。

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # method 1: curicular swap.
        # the elements at [i, j] will be transferred to [j, n-1-i],
        # [j, n-1-i] to [n-1-i, n-1-j],
        # [n-1-i, n-1-j] to [n-1-j, i],
        # and [n-1-j, i] to [i, j].
        # the point is how to decide the range of i and j.
        # if N is even, i lies between (0, (N/2)-1) and so does j.
        # if N is odd, i lies between (0, (N/2)-1) and j lies between (0, N/2).
        N = len(matrix)
        i_max = N // 2 - 1
        if N % 2 == 0:
            j_max = N // 2 - 1
        else:
            j_max = N // 2
        for i in range(i_max + 1):
            for j in range(j_max + 1):
                temp = matrix[i][j]
                matrix[i][j] = matrix[N-1-j][i]
                matrix[N-1-j][i] = matrix[N-1-i][N-1-j]
                matrix[N-1-i][N-1-j] = matrix[j][N-1-i]
                matrix[j][N-1-i] = temp

```