# 解题思路
1. 本质：在一个网格里找一个word，意思就是在图里找word这条路径，且这条路径不能有环
2. 开始点存在多处，所以需要遍历网格，每个开始点都得找。
3. 需要一个对应的状态图，标志着此次查找的已经走过的路径
3. 因为某条路径可能走着走着不通，回到某个位置接着找，所以需要层层回溯，且将不通但已经访问过的点标记成未访问，已供下次可能的路径使用

```python []
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        n = len(board)
        m = len(board[0])
        if not word or not n or not m:
            return false
        
        def dfs(board, visited, curr, word):
            i, j = curr
            # 该点已经被遍历过
            if visited[i][j]:
                return False
            
            # 没遍历过，但是已经遍历完了word
            if not word:
                return True
            
            # 标记已经访问
            visited[i][j] = True
            
            if i > 0 and board[i-1][j] == word[0]:   # up
                if dfs(board, visited, (i-1, j), word[1:]):
                    return True
            if i < (n-1) and board[i+1][j] == word[0]:   # down
                if dfs(board, visited, (i+1, j), word[1:]):
                    return True
            if j > 0 and board[i][j-1] == word[0]:  # left
                if dfs(board, visited, (i, j-1), word[1:]):
                    return True
            if j < (m-1) and board[i][j+1] == word[0]:  # right
                if dfs(board, visited, (i, j+1), word[1:]):
                    return True
            
            # 三个方向都没找到，所以回溯，并将该点置成unvisited！！！这个很关键，因为其他路径可能再次需要
            visited[i][j] = False
            
            return False
            
                
        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0]:
                    visited = [[False]*m for _ in range(n)]
                    if dfs(board, visited, (i, j), word[1:]):
                        return True
        return False
```