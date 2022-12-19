
```python
class Solution:
    def exist(self, board, word: str) -> bool:
        if (len(board) == 0 or len(board[0]) == 0) and len(word) > 0:
            return False
        y, x, len_y, len_x,path,res = 0, -1, len(board), len(board[0]),[],word
        while len(res) > 0:
            if len(path):
                y, x, v = path.pop()
                if board[y][x] is None:# 还原使用过的点
                    board[y][x] = v
                    res = v + res
                elif board[y][x] == res[0]:
                    if len(res) == 1:
                        return True
                    path.append((y, x, res[0]))
                    board[y][x] = None # 标记使用过的点
                    res = res[1:]
                    for _y, _x in [(y, x + 1), (y + 1, x), (y, x - 1), (y - 1, x)]:
                        has_n = 0 <= _y < len_y and 0 <= _x < len_x
                        if has_n and board[_y][_x]: # 可能的点
                            path.append((_y, _x, res))
            else:# 没有点了, 则按board顺序重新开始找
                x += 1
                if x == len_x:
                    x = 0
                    y += 1
                path = [(y, x, word)]
                if y == len_y:
                    break
        return len(word) == 0
```