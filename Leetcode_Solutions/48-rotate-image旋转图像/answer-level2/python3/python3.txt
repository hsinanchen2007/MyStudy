先交换矩阵的每一行，即第1行和倒数第一行交换，第二行和倒数第二行交换。。。。。，然后在求一个转置就行了
![UC截图20191202221732.png](https://pic.leetcode-cn.com/1b97afa2b1629f42234aa732e85bf60d1dfcf01f26fb4f8d10154ae26eb9baaf-UC%E6%88%AA%E5%9B%BE20191202221732.png)
```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n//2):
            matrix[i],matrix[n-i-1] = matrix[n-i-1],matrix[i]
        for i in range(0,n):
            for j in range(i+1,n):
                matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
```
