### 解题思路
观察很容易发现第1行变成第三列，第二行变成第二列，第三行变成第一列。
容易实现的是第一行变第一列，第二行变第二列。。
于是先把第一行变第第三行，第二行变第二行，行交换。


### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        length=len(matrix)
        for i in range(length//2):
            matrix[i],matrix[length-1-i]=matrix[length-1-i],matrix[i]
        for i in range(length):
            for j in range(0,i):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
```