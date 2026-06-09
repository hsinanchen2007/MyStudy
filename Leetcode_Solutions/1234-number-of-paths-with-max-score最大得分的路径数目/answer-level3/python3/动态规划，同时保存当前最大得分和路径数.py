```
class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        length = len(board)
        board[length-1] = board[length-1].replace('S', '0') # 为了处理最后的元素
        dp = [[[-1,-1] for _ in range(length)] for _ in range(length)]
        dp[0][0] = [0, 1] # 位置0表示当前最大得分, 位置1表示最大得分路径数
        dp[length-1][length-1] = [0,0]
        for i in range(length):
            for j in range(length):
                # print(i,j)
                if i > 0 and j > 0:
                    if board[i][j] != 'X':
                        score = [dp[i-1][j-1][0], dp[i-1][j][0], dp[i][j-1][0]] # 到达当前点的三条路径
                        path  = [dp[i-1][j-1][1], dp[i-1][j][1], dp[i][j-1][1]]
                        max_score = max(score)
                        max_path = 0
                        if max_score != -1: # 最大得分-1，表示当前点不可达
                            for k in range(3): #存在多个最大得分，就合并路径数
                                if score[k] == max_score:
                                    max_path += path[k]
                            dp[i][j][0] = max_score + int(board[i][j])
                            dp[i][j][1] = max_path          
                elif j == 0:
                    if board[i][j] != 'X':
                        if dp[i-1][j][0] != -1:
                            dp[i][j][0] = int(board[i][j]) + dp[i-1][j][0]
                            dp[i][j][1] = 1
                            # print(dp[i][j])
                elif i == 0:
                    if board[i][j] != 'X' and j > 0 and board[i][j-1][0] != -1:
                        dp[i][j][0] = int(board[i][j]) + dp[i][j-1][0]
                        dp[i][j][1] = 1
                # print(i,j)
        return [dp[i][j][0], dp[length-1][length-1][1] % (10**9 + 7)]
```
