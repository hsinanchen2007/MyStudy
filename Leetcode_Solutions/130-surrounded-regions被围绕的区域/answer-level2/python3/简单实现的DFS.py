极其基本的解法，没有优化效率或者巧妙思路等
```
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board: return
        
        R = len(board)
        C = len(board[0])

        def neigbors(i, j):
            for row, col in ((i-1, j), (i+1, j), (i, j-1), (i, j+1)):
                if 0<=row<R and 0<=col<C:
                    yield (row, col)
        
        # 边界上的所有点
        borders = [(0, j) for j in range(C)] + [(i, 0) for i in range(1, R)] \
                + [(R-1, j) for j in range(1, C)] + [(i, C-1) for i in range(1, R-1)]
        
        visited = [[False for _ in range(C)] for _ in range(R)]

        queue = []

        # 将边界上为`O`的点加入queue中，并DFS与其相连的`O`
        for i, j in borders:
            if board[i][j] == 'O':
                queue.append((i, j))
                visited[i][j] = True
        
        while queue:
            i, j = queue.pop(0)

            for row, col in neigbors(i, j):
                if not visited[row][col] and board[row][col] == 'O':
                    queue.append((row, col))
                    visited[row][col] = True
        
        # 最后将不与边界上`O`相连的`O`翻转。
        for i in range(R):
            for j in range(C):
                if not visited[i][j] and board[i][j] == 'O':
                    board[i][j] = 'X'
  
```
