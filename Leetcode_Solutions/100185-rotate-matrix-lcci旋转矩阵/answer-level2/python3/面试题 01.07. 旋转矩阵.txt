### 解题思路
矩阵反转
### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return matrix
        # 上下反转
        matrix[:] = matrix[::-1]# 倒序
        # 中心轴反转
        for i in range(len(matrix)):            
            for j in range(i, len(matrix[i])):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        return matrix
```