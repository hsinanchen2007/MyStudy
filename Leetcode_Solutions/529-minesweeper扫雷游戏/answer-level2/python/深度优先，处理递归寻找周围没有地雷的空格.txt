### 解题思路
代码思路：
1. 当点击的格子是地雷，将其改为'X'，并返回board；
2. 当点击的格子是'E'，那么环顾8个方向，统计出有 count_m个地雷：
        1. 如果count_m不为0，那么周围有地雷，将这个格子设置为str(count_m)；
        2. 如果count_m为0，周围没有地雷，那么进入遍历模式，创建一个栈，只有周围没有地雷的格子才进栈，都是'B'，然后从8个方向查看周围格子的地雷情况，将周围没有地雷的格子添加到栈中，将周围有地雷的格子设置为地雷数量。

### 代码

```python3
class Solution:
    def updateBoard(self, board, click):
        r = len(board) - 1
        l = len(board[0]) - 1
        directions = [
            lambda node: [node[0] + 1, node[1] + 1],
            lambda node: [node[0], node[1] + 1],
            lambda node: [node[0] - 1, node[1] + 1],
            lambda node: [node[0] - 1, node[1]],
            lambda node: [node[0] - 1, node[1] - 1],
            lambda node: [node[0], node[1] - 1],
            lambda node: [node[0] + 1, node[1] - 1],
            lambda node: [node[0] + 1, node[1]],
        ]
        if board[click[0]][click[1]] == 'M':
            board[click[0]][click[1]] = 'X'
            return board
        elif board[click[0]][click[1]] == 'E':
            count_m = 0
            for direction in directions:
                x, y = direction(click)
                if 0 <= x <= r and 0 <= y <= l:
                    if board[x][y] == 'M':
                        count_m += 1
            if count_m:
                board[click[0]][click[1]] = str(count_m)
                return board
            else:
                board[click[0]][click[1]] = 'B'
                stack = list()
                stack.append(click)
                while stack:
                    node = stack[-1]
                    # print(stack)
                    # time.sleep(0.3)
                    for direction in directions:
                        x, y = direction(node)
                        if 0 <= x <= r and 0 <= y <= l and board[x][y] == 'E':
                            count_m = 0
                            for direction in directions:
                                x1, y1 = direction([x, y])
                                if 0 <= x1 <= r and 0 <= y1 <= l:
                                    if board[x1][y1] == 'M':
                                        count_m += 1
                            # print(count_m)
                            if count_m:
                                board[x][y] = str(count_m)
                            else:
                                board[x][y] = 'B'
                                stack.append([x, y])
                                break
                    else:
                        stack.pop()
                return board

```