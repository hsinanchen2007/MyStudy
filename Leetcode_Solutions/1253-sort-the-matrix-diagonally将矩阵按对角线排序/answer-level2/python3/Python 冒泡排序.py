冒泡排序加上一层循环就能过，无需额外空间。

``` python
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        for k in range(1, min(m,n)):
            for i in range(m-k):
                for j in range(n-k):
                    if mat[i][j] > mat[i+1][j+1]:
                        mat[i][j], mat[i+1][j+1] = mat[i+1][j+1], mat[i][j]
        return mat
```