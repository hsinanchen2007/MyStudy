1、寻找R的位置
2、从R的位置出发，上下左右，如果遇见B就停止搜索，如果遇见p，则结果+1，并停止搜索

最终返回结果

### 代码

```python
class Solution(object):
    def numRookCaptures(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """

        self.ans = 0
        def dfs(x,y,dx, dy):
            if x<0 or x>7 or y<0 or y>7: return
            if board[x][y]=="B":return
            if board[x][y]=="p":
                self.ans +=1
                board[x][y] = "."
                return
            dfs(x+dx, y+dy, dx, dy)

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'R':
                    dfs(i-1,j,-1,0)
                    dfs(i+1,j,1,0)
                    dfs(i,j+1,0,1)
                    dfs(i,j-1,0,-1)
        return self.ans
```