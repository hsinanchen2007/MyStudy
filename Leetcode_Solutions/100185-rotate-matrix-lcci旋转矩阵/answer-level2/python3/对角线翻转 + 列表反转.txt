只要两步，首先我们把矩阵沿着对角线翻转，然后对每一行的一个列表，使用 `reverse()` 进行反转。

![image.png](https://pic.leetcode-cn.com/8f785f06e0d5334fdf103cebccbc9d82f0664698f9b1c2998730d5d801625e9f-image.png)


贴上代码：

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix[0])
        for i in range(N):
            for j in range(i, N, 1):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for i in range(N):
            matrix[i].reverse()
```
