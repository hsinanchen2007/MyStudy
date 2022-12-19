![image.png](https://pic.leetcode-cn.com/54de6e62593a7adedd466a5b4fde585f256a79f827ecaa79d3be6adafa55b202-image.png)
```
python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m,n=len(matrix),len(matrix[0])
        for i in range(m):
            for j in range(i+1,n):
                matrix[j][i],matrix[i][j]=matrix[i][j],matrix[j][i]
        
        for i in range(m):
            matrix[i].reverse()
```
