遍历到'.'不用管
每遍历到一个'X'，战舰计数+1，并把这个战舰其余部分的'X'替换为'.'
遍历完成后直接return战舰计数
```
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        rows = len(board)
        cols = len(board[0])
        ans = 0
        for row in range(rows):
            for col in range(cols):
                if board[row][col] == 'X':
                    ans += 1
                    i = row
                    j = col
                    while j+1 < cols and board[i][j+1] == 'X':
                        board[i][j+1] = '.'
                        j += 1
                    while i+1 < rows and board[i+1][j] == 'X':
                        board[i+1][j] = '.'
                        i += 1
        return ans
```
