### 解题思路
通过两个例子发现方阵旋转90度，其实是把每一行进行反转，然后按照主对角线的方向对矩阵进行交换
为了只交换一次，每一行需要比前一行少进行交换一个元素。
交换是通过异或进行的，刚开始我也不明白是怎么实现的，通过这篇文章看懂的。
https://blog.csdn.net/lewky_liu/article/details/85219084

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N=len(matrix)
        for i in range(N):
            matrix[i].reverse()
        for i in range(N):
            for x in range (N-i):
                if matrix[i][x]==matrix[N-x-1][N-i-1]:
                    continue
                matrix[i][x]=matrix[i][x]^matrix[N-x-1][N-i-1]
                matrix[N-x-1][N-i-1]=matrix[i][x]^matrix[N-x-1][N-i-1]
                matrix[i][x]=matrix[i][x]^matrix[N-x-1][N-i-1]

```