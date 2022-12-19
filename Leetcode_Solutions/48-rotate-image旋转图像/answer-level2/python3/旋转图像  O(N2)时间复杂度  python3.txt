### 解题思路
先转置矩阵
然后把矩阵的每一行翻转

![翻转图像.png](https://pic.leetcode-cn.com/4e81413fe21b80c9d88864be2acececd63758bdc03d620efa9c3d496d0b1108c-%E7%BF%BB%E8%BD%AC%E5%9B%BE%E5%83%8F.png)


### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n):
            for j in range(i, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for i in matrix:
            i.reverse()
                
```