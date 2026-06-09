```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m,n = len(board),len(board[0])
        visited = [[0]*n for _ in range(m)]
        def search(i,j,word):
            # print(word)
            if i<0 or j<0 or i>=m or j >=n or visited[i][j]==1 or board[i][j]!=word[0]:
                return False
            if len(word)==1: return True
            visited[i][j]=1
            
            a = search(i-1, j, word[1:]) or search(i+1, j, word[1:]) or search(i, j-1, word[1:]) or search(i, j+1, word[1:])
            #修正i,j为false时visited的值
            if a: return True
            else:
                visited[i][j]=0
                return False
        
        for i in range(m):
            for j in range(n):
                if board[i][j]==word[0]: #减少不必要的搜索30% -> 80%
                    f = search(i, j, word)
                    if f:
                        return True
        return False
```
