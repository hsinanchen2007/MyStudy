```
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m = len(board)
        n = len(board[0])
        l = len(word)
        flag = [[0]*n for _ in range(m)]
        direction = [[0,-1],[0,1],[-1,0],[1,0]]
        def helper(i,j,k):
            if board[i][j] == word[k]:    
                flag[i][j] = 1
                if k == l-1:
                    return True
                else:
                    for d in direction:
                        ni = i+d[0]
                        nj = j+d[1]
                        if 0 <= ni < m and 0 <= nj < n and flag[ni][nj] == 0 and helper(ni,nj,k+1):
                            return True
            flag[i][j] = 0
            return False
        for i in range(m):
            for j in range(n):
                if helper(i,j,0):                    
                    return True
        return False
```
