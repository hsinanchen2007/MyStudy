规则：
- 'M' 代表一个未挖出的地雷
- 'X' 则表示一个已挖出的地雷。
- 'E' 代表一个未挖出的空方块，
- 'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，
- 数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，

边界条件：
- 现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
- 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
- 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的方块都应该被递归地揭露。
- 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
- 如果在此次点击中，若无更多方块可被揭露，则返回面板。

如果click是'M'，那么就是踩雷了设定为X退出，返回棋盘。
如果不是分别进入DFS和BFS
- DFS首先设定边界条件如果不是‘E’return。剩下的就是和200岛屿问题一样进行DFS，只不过这里是八连通
```python
class SolutionDFS:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        if not board:
            return []
        m,n=len(board),len(board[0])
        i,j=click[0],click[1]
        if board[i][j] == 'M':
            board[i][j] = 'X'
            return board
        self.dfs(board,i,j)
        return board
    
    def dfs(self,board,i,j):
        if board[i][j] != 'E':
            return
        m,n=len(board),len(board[0])
        directions = [(-1,-1), (0,-1), (1,-1), (1,0), (1,1), (0,1), (-1,1), (-1,0)]
        mine_count = 0
        for d in directions:
            ni,nj=i+d[0],j+d[1]
            if 0<=ni<m and 0<=nj<n and board[ni][nj]=='M':
                mine_count+=1
        if mine_count == 0:
            board[i][j] = 'B'
        else:
            board[i][j] = str(mine_count)
            return
        
        for d in directions:
            ni,nj=i+d[0],j+d[1]
            if 0 <= ni <m and 0<=nj<n:
                self.dfs(board,ni,nj)
```

- BFS：可以当做BFS模板的思路了没遍历过的放到queue标记board，完成后放到visited
```python
class SolutionBFS:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        m,n=len(board),len(board[0])
        i,j=click[0],click[1]
        if board[i][j] == "M":
            board[i][j] = "X"
        directions = [(-1,-1), (0,-1), (1,-1), (1,0), (1,1), (0,1), (-1,1), (-1,0)]
        import collections
        q = collections.deque()
        q.append(click)
        visited = set(click)
        
        def numBombs(board,i,j):
            mine_count = 0
            for d in directions:
                ni, nj = i + d[0], j + d[1]
                if 0<=ni<m and 0<=nj<n and board[ni][nj] == 'M':
                    mine_count+=1
            return mine_count
        while q:
            for _ in range(len(q)):
                x,y=q.popleft()
                if board[x][y] == 'E':
                    bombsNextTo = numBombs(board,x,y)
                    board[x][y] = "B" if bombsNextTo == 0 else str(bombsNextTo)
                    if bombsNextTo == 0:
                        for d in directions:
                            ni, nj = x + d[0], y + d[1]
                            if 0<=ni<m and 0<=nj<n and (ni,nj) not in visited:
                                q.append((ni,nj))
                                visited.add((ni,nj))
        return board
```
更多内容：https://www.cnblogs.com/buro79xxd/