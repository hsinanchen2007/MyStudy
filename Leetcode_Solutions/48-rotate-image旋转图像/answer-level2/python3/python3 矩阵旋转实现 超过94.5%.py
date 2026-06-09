
![image.png](https://pic.leetcode-cn.com/30a914ef96cad14a866fc44387d106c477c7aec2d8f47729e85e338a2989888d-image.png)
```python []
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        '''矩阵转置'''
        for x in range(len(matrix)):
            for y in range(x):
                matrix[x][y], matrix[y][x] = matrix[y][x], matrix[x][y]
        
        '''转置后列变换'''
        for i in range(len(matrix)):
            for j in range(len(matrix[i])//2):
                matrix[i][j],matrix[i][len(matrix)-1-j] = matrix[i][len(matrix)-1-j], matrix[i][j]
```

顺时针旋转90度，可以根据转置矩阵的性质，先得到转置矩阵，再进行列交换，即可实现