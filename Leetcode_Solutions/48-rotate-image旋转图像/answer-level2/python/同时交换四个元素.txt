### 解题思路
同时交换四个元素

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        x=len(matrix)
        if x%2==1:
            for i in range(int(x/2)):
                for j in range(int(x/2)+1):
                    matrix[i][j],matrix[j][x-1-i]=matrix[j][x-1-i],matrix[i][j]
                    matrix[i][j],matrix[x-1-i][x-1-j]=matrix[x-1-i][x-1-j],matrix[i][j]
                    matrix[i][j],matrix[x-1-j][i]=matrix[x-1-j][i],matrix[i][j]
        else:
            for i in range(int(x/2)):
                for j in range(int(x/2)):
                    matrix[i][j],matrix[j][x-1-i]=matrix[j][x-1-i],matrix[i][j]
                    matrix[i][j],matrix[x-1-i][x-1-j]=matrix[x-1-i][x-1-j],matrix[i][j]
                    matrix[i][j],matrix[x-1-j][i]=matrix[x-1-j][i],matrix[i][j]
```