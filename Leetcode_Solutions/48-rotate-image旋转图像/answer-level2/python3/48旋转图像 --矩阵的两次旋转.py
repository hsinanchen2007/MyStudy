### 解题思路
#### 1.转置（绕主对角线旋转）：
如
1 2 3  =>  1 4 7
4 5 6  =>  2 5 8
7 8 9  =>  3 6 9
#### 2.每行反转：
如
1 4 7  =>  7 4 1
2 5 8  =>  8 5 2
3 6 9  =>  9 6 3
### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m=len(matrix)
        n=len(matrix[0])
        for i in range(m):#先进行对角线旋转
            for j in range(i,m):
                if i != j:
                    matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
        for row in matrix:#每行反转
            row.reverse()


        

```