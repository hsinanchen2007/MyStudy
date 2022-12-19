### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:return board
        # 从边界出发，BFS寻找和边界连通的O,连通则替换为#
        queue = []
        # 第一行和最后一行
        row = len(board) 
        col = len(board[0]) 
        for i in range(col):
            if board[0][i] == 'O':
                queue.append((0, i))
            if board[row - 1][i] == 'O':
                queue.append((row - 1, i))
        # 第一列和最后一列
        for i in range(row):
            if board[i][0] == 'O':
                queue.append((i, 0))
            if board[i][col - 1] == 'O':
                queue.append((i, col - 1))
        while queue:
            current = queue.pop(0)
            board[current[0]][current[1]] = '$'
            for x, y in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                tx = current[0] + x
                ty = current[1] + y
                if not (0 <= tx < row and 0 <= ty < col):
                    continue
                elif board[tx][ty] == 'O':
                    queue.append((tx, ty))
        # 遍历将O替换为X,将#替换为O
        for i in range(row):
            for j in range(col):
                if board[i][j] == '$':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
        
                    

        


```