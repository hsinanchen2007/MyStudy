执行用时 :32 ms, 在所有 python3 提交中击败了96.94%的用户
内存消耗 :12.6 MB, 在所有 python3 提交中击败了99.38%的用户

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        I = 0
        J = 9
        cntL = 0
        cntR = 0
        cntU = 0
        cntD = 0
        for i in range(8):
            if 'R' in board[i]:
                I = i
        for j in range(8):
            if board[I][j] == 'p' and j<J:
                cntL = 1
            elif board[I][j] == 'B' and j<J:
                cntL = 0
            elif board[I][j] == 'R':
                J = j
            elif board[I][j] == 'B' and j>J:
                break
            elif board[I][j] == 'p' and j>J:
                cntR = 1
        for i in range(8):
            if board[i][J] == 'p' and i<I:
                cntU = 1
            elif board[i][J] == 'B' and i<I:
                cntU = 0
            elif board[i][J] == 'B' and i>I:
                break
            elif board[i][J] == 'p' and i>I:
                cntD = 1
        return cntL + cntR + cntU + cntD


```