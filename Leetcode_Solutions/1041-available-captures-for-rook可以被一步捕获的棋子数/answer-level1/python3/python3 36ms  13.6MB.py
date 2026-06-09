1. 先找到R的位置
2. 将R所在的行列的字符拼接起来，然后去掉“.”
3. 将Rp pR的个数加起来

```
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        result = 0
        row_str = ""
        column_str = ""
        for i in range(8):
            if 'R' in board[i]:
                j = board[i].index('R')
                break
        row_str = "".join(board[i]).replace(".","")
        column_str = "".join([board[k][j] for k in range(8) if board[k][j] != "."])
        result = row_str.count('Rp')+row_str.count('pR')+column_str.count('Rp')+column_str.count('pR')
        return result
```
