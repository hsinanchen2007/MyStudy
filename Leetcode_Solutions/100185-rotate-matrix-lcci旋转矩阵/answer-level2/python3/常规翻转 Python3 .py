### 解题思路
此处撰写解题思路


### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        l = len(matrix)
        for i in range(l):#左右翻转
            for j in range(l//2):
                matrix[i][j],matrix[i][l-j-1] = matrix[i][l-j-1],matrix[i][j]
        
        for i in range(l):#对角线翻转
            for j in range(l-i):
                matrix[i][j],matrix[l-j-1][l-i-1] = matrix[l-j-1][l-i-1],matrix[i][j]
        
        return
```