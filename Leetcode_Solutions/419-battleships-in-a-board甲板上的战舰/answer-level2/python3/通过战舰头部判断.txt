## 思路:

我们可以通过战舰的头来判断个数，当一个点上面或者左面试`X`说明它战舰中间部分，跳过即可！

## 代码:

```python
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        row = len(board)
        col = len(board[0])
        res =  0
        for i in range(row):
            for j in range(col):
                if board[i][j] == ".": continue
                if i > 0 and board[i - 1][j] == "X": continue
                if j > 0 and board[i][j - 1] == "X": continue
                res += 1
        return res
```

