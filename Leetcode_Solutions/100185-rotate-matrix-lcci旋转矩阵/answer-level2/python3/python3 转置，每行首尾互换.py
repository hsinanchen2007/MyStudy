### 解题思路
此处撰写解题思路
先转置，然后双指针每行的首尾互换很简单。。
复杂度
时间 O(n^2)
空间 O(1) 
每次交换用到的中间变量，应该算是O(1) 把
### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n):
            for j in range(i+1,n):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
        # print(matrix)
        for i in range(n):
            for j in range(n//2):
                matrix[i][j],matrix[i][n-j-1] = matrix[i][n-j-1],matrix[i][j]
        


```