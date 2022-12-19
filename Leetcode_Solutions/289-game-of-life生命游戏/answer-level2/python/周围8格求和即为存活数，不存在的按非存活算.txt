### 解题思路
**周围8格求和即为存活数，不存在的按非存活算**

##### 1、修改当前值 不依赖额外的空间存储
```
if 存活 and 满足接着存活的条件
    修改值为 0b11 计算时候 & 1 不影响当前计算结果，下次存活结果即为>>1
elif 非存活 and 满足存活条件
    修改值为 0b10 计算时候 & 1 还是非存活，不影响当前计算结果，下次存活结果即为>>1
else
    剩下的全是非存活了,直接>>1 即可
```
##### 2、按条件判断记录需要发生变更的位置的坐标
### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rowCount = len(board)
        if rowCount < 1:
            return
        columnCount = len(board[0])
        neighbor = [[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]
        record = []
        for row in range(rowCount):
            for column in range(columnCount):
                lives = 0
                for i, j in neighbor:
                    if 0 <= row + i < rowCount and 0 <= column + j < columnCount:
                        lives += board[row + i][column + j] & 1
                if  board[row][column] and 2 <= lives <= 3:
                    board[row][column] = 3
                elif not board[row][column] and 3 == lives:
                    board[row][column] = 2

        for row in range(rowCount):
            for column in range(columnCount):
                board[row][column] >>= 1



    def gameOfLife1(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rowCount = len(board)
        columnCount = 0
        record = []
        for i in range(rowCount):
            columnCount = len(board[i])
            for j in range(columnCount):
                sum = ( 1 if i > 0 and j > 0 and 1 == board[i-1][j-1] else 0 )\
                    + ( 1 if i > 0 and 1 == board[i-1][j] else 0 )\
                    + ( 1 if i > 0 and j < columnCount - 1 and 1 == board[i-1][j+1] else 0 )\
                    + ( 1 if j > 0 and 1 == board[i][j-1] else 0 )\
                    + ( 1 if j < columnCount - 1 and 1 == board[i][j+1] else 0 )\
                    + ( 1 if i < rowCount - 1 and j > 0 and 1 == board[i+1][j-1] else 0 )\
                    + ( 1 if i < rowCount - 1 and 1 == board[i+1][j] else 0 )\
                    + ( 1 if i < rowCount - 1 and j < columnCount - 1 and 1 == board[i+1][j+1] else 0 )
                if 1 == board[i][j] and (sum < 2 or sum > 3):
                    record.append([i, j])
                elif 0 == board[i][j] and 3 == sum:
                    record.append([i, j])
        for i, j in record:
            board[i][j] = 1 if 0 == board[i][j] else 0


```