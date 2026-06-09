
### 解析

题目
```
[
    [0,1,0],
    [0,0,1],
    [1,1,1],
    [0,0,0]
]
```

思路
1. 第一次遍历，对于每个位置，计算周围的细胞数目，保存
2. 第二次遍历，根据当前位置细胞状态和周围细胞数目，设置最终细胞状态

这里有个问题，如何原地存储细胞数目信息？
1. 用当前位置数字的**最后一位**储存原来是否有细胞（0，1）
2. 将周围细胞数目的值，**左移一位**
3. 将这两个值做**按位或**运算


### 代码
```python
class Solution(object):
    def gameOfLife(self, board):
        def count_cell(x, y):  
            points = [
                (x-1, y-1),
                (x-1, y),
                (x-1, y+1),
                (x, y-1),
                (x, y+1),
                (x+1, y-1),
                (x+1, y),
                (x+1, y+1),
            ]
            return sum((board[i][j] & 1) for i, j in points if 0 <= i < max_x and 0 <= j < max_y)

        if not board:
            return board

        max_x, max_y = len(board), len(board[0])

         # 计算周围细胞数目，并储存
        for i in range(max_x):
            for j in range(max_y):
                count = count_cell(i, j)
                count <<= 1
                board[i][j] |= count

        for i in range(max_x):
            for j in range(max_y):
                count = board[i][j] >> 1   # 右移一位，取出周围细胞数目
                board[i][j] &= 1   # 重新设置原先细胞状态
                if board[i][j] == 1:
                    if count < 2 or count > 3:
                        board[i][j] = 0
                else:
                    if count == 3:
                        board[i][j] = 1
        return board
```
