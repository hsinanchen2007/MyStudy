刚看题目的时候有点懵，结合例子也猜不透题意。

**题目意思：**
以 `R` 的起始位置为中心，往上、下、左和右四个方向前进，遇到
    `B`： 自己人则停下
    `p`： 敌方则捕获，捕获敌人数加 1
    `.`： 忽略，继续前进
直到碰到棋盘边界，也就是 index 0 或 7， 处理完就停下，然后继续处理其他可行的格子

```
class Solution(object):
    def numRookCaptures(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        upban, downban, leftban, rightban = 0, 8, 0, 8 # 上下左右的边界
        def neighbor(r, c):
            “”“以起始位置为中心，向上下左右四个方向前进，一次返回一个格子的位置”“”
            for i in range(1, 8):
                up = (r-i, c) if r-i >= upban else None
                down = (r+i, c) if r+i < downban else None
                left = (r, c-i) if c-i >= leftban else None
                right = (r, c+i) if c+i < rightban else None
                yield from (up, down, left, right) 

        res = 0 # 捕获敌人的计数器
        for r, row in enumerate(board):
            for c, col in enumerate(row):
                if col == 'R': # 找到车车
                    for n in neighbor(r, c): # 遍历车车可以走的格子
                        if n:
                            nr, nc = n
                            # 判断格子是否'B', 'p'以及更新位置的边界
                            if board[nr][nc] in ('B', 'p'):
                                if nr==r and nc > c: # right
                                    rightban = nc
                                elif nr==r and nc < c: # left
                                    leftban = nc
                                elif nr > r and nc == c: # down
                                    downban = nr
                                else: # up
                                    upban = nr
                                if board[nr][nc] == 'p':
                                    res += 1
                    break
        return res
```
