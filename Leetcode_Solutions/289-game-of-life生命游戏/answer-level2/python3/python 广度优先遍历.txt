```
from collections import deque
import copy
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows, cols= len(board), len(board[0])
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]     # 八个方向
        directions = set(directions)        #提升查找效率
        tmpBoard = copy.deepcopy(board)     # 深拷贝，因为需要原地修改，浅拷贝或者不用另外空间会导致问题
        queue = deque()
        for row in range(rows):
            for col in range(cols):
                cnt = 0     # 用于记录活细胞数量
                for direction in directions:        # 统计八个方向所有点
                    newRow, newCol = row + direction[0], col + direction[1]
                    if 0 <= newRow < rows and 0 <= newCol < cols:
                        queue.append((newRow, newCol))
                while queue:
                    curRow, curCol = queue.popleft()
                    if tmpBoard[curRow][curCol] == 1:
                        cnt += 1
                if board[row][col] == 1:
                    if cnt < 2 or cnt > 3:
                        board[row][col] = 0
                else:
                    if cnt == 3:
                        board[row][col] = 1
```
