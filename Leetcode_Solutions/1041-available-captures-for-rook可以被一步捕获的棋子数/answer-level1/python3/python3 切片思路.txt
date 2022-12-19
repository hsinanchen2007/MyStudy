### 解题思路
python3 切片思路

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        i, j = 0, 0
        is_find = False
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    is_find = True
                    break
            if is_find:
                break
        out = 0
        # 横向
        tmp = ''.join(board[i])
        out += tmp[:j].rfind('p') > tmp[:j].rfind('B')
        out += tmp[:j:-1].rfind('p') > tmp[:j:-1].rfind('B')

        # 翻转矩阵
        board = list(map(list, zip(*board)))
        i, j = j, i

        # 纵向
        tmp = ''.join(board[i])
        out += tmp[:j].rfind('p') > tmp[:j].rfind('B')
        out += tmp[:j:-1].rfind('p') > tmp[:j:-1].rfind('B')

        return out
```