### 解题思路

题目要求比较简单，并且提示中也给出了建议，所以，
个人愚钝，就只好采用了暴力方式：
- 遍历每一个网格，记录其周围八个方向的活细胞数量；
- 使用字典或者其他方式都可以，记录下该位置细胞的更新状态（不能直接单个修改，这样会影响其他细胞状态的判断，题目提示中有说明这点）；
- 最后再从字典中，根据坐标依次更新原有细胞的存活状态；

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = len(board)
        cols = len(board[0])
        
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, 1), (1, -1)]
        dct = {}
        for i in range(rows):
            for j in range(cols):
                live = 0
                dct[(i, j)] = board[i][j] + 0

                for dx, dy in directions:
                    cur_x = i + dx
                    cur_y = j + dy

                    if cur_x < 0 or cur_x >= rows:
                        continue
                    if cur_y < 0 or cur_y >= cols:
                        continue
                    
                    if board[cur_x][cur_y] == 1:
                        live += 1
                
                if board[i][j] == 1:
                    if live < 2 or live > 3:
                        dct[(i, j)] = 0
                else:
                    if live == 3:
                        dct[(i, j)] = 1

        for x, y in dct.keys():
            board[x][y] = dct[(x, y)]
        pass
```