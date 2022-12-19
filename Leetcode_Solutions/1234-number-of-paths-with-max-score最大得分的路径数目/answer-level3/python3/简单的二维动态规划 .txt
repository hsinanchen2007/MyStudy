```
class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        m = len(board)
        dp = [[[-1,1] for _ in range(m+1)] for i in range(m+1)]
        for i in range(m-1, -1, -1):
            for j in range(m-1, -1, -1):
                if board[i][j] == 'E' or board[i][j] == 'S':
                    dp[i][j][0] = 0
                elif board[i][j] == 'X':
                    continue           
                else:
                    if max(dp[i+1][j+1][0], dp[i][j+1][0], dp[i+1][j][0]) != -1:
                        cur = max(dp[i+1][j+1][0], dp[i][j+1][0], dp[i+1][j][0])
                        dp[i][j][0] = cur + int(board[i][j])
                        dp[i][j][1] = sum([i[1] for i in [dp[i+1][j+1], dp[i][j+1],dp[i+1][j]] if i[0] == cur])
        finalnum = max(dp[1][0][0],dp[1][1][0],dp[0][1][0])
        if finalnum != -1:
            finalsum = sum([i[1] for i in [dp[1][0],dp[1][1],dp[0][1]] if i[0] == finalnum])
            return [finalnum % (10**9 + 7),finalsum % (10**9 + 7)]
        else:return [0,0]
```
