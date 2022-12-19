### 解题思路
模拟的思路，代码与之前的螺旋矩阵I差不多，只不过这里变成了填坑。时间复杂度就是矩阵的个数O(n^2)。

### 代码

```python3
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        square_matrix = []
        for i in range(n):
            square_matrix.append([0]*n)
        # 模拟撞墙转向的过程
        count=1
        i=j=0
        while count<=n*n:
            # 向右
            while 0<=i<n and 0<=j<n and square_matrix[i][j]==0:
                square_matrix[i][j]=count
                j+=1
                count+=1
            i+=1
            j-=1
            # 向下
            while 0<=i<n and 0<=j<n and square_matrix[i][j]==0:
                square_matrix[i][j]=count
                i+=1
                count+=1
            i-=1
            j-=1
            # 向左
            while 0<=i<n and 0<=j<n and square_matrix[i][j]==0:
                square_matrix[i][j]=count
                j-=1
                count+=1
            i-=1
            j+=1
            # 向上
            while 0<=i<n and 0<=j<n and square_matrix[i][j]==0:
                square_matrix[i][j]=count
                i-=1
                count+=1
            i+=1
            j+=1
        return square_matrix
```