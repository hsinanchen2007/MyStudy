### 解题思路
先设定可增加的x，y坐标列表，然后找到R所在的坐标，最后按规则行走

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        add_x = [0, 1, 0, -1]
        add_y = [1, 0, -1, 0]
        p_get = 0
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    star_x = i
                    star_y = j
        for i in range(4):
            step = 0
            while True:
                cur_x = star_x + add_x[i] * step
                cur_y = star_y + add_y[i] * step
                if cur_x < 0 or cur_y < 0 or cur_x >= 8 or cur_y >= 8 or board[cur_x][cur_y] == "B":
                    break
                if board[cur_x][cur_y] == "p":
                    p_get += 1
                    break
                step += 1
        return p_get



```