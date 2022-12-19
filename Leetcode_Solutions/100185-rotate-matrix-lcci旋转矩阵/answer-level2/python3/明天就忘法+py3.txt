### 解题思路
 

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # if not matrix:
        #     return 
        # m=len(matrix)
        # n=len(matrix[0])
        # # 左右对换
        # for i in range(m):
        #     for j in range(n//2):
        #         matrix[i][n-1-j],matrix[i][j]=matrix[i][j],matrix[i][n-1-j]
        
        # # 斜对角线交换 不是主对角线
        # for i in range(m):
        #     for j in range(n-i):
        #         matrix[i][j],matrix[m-1-j][m-1-i]=matrix[m-1-j][m-1-i],matrix[i][j]
        # return matrix

        # 上下翻转和主对角线翻转
        if not matrix:
            return
        m=len(matrix)
        n=len(matrix[0])
        # 上下翻转
        for i in range(m//2):
            for j in range(n):
                matrix[m-1-i][j],matrix[i][j]=matrix[i][j],matrix[m-1-i][j]
        # 主对角线翻转
        for i in range(m):
            for j in range(i):
                matrix[j][i],matrix[i][j]=matrix[i][j],matrix[j][i]
        return matrix
```