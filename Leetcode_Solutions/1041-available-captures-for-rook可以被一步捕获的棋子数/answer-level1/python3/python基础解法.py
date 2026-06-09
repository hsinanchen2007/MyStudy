### 解题思路
这道题首先是要找到哪一行哪一列有R，找到以后两个循环分别输出，通过将‘.’替换为''，这样的话Rp，pR就是可以捕获的量。

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        result = 0
        for i in range(len(board)):
            if 'R' in board[i]:
                raw = i
                break
        colum = board[raw].index('R')

        raws = ''.join(board[raw])
        raws = raws.replace('.','')
        cols = ''.join(i[colum] for i in board)
        cols = cols.replace('.','')
        if 'pR' or 'Rp' in raws:
            result += 1
        if 'pR' or 'Rp' in cols:
        return result
```