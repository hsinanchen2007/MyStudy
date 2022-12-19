### 解题思路
将1->0这个变化增加一个1->3->0
0->1也变成 0->2->1
这样在判断时1，3都表示活细胞。
最后再更新一遍即可。

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 思路，更新会互相影响，要设定一个中间状态，最后再处理一下。
        m = len(board)
        n = len(board[0])
        for i, line in enumerate(board):
            for j, item in enumerate(line):
                if item == 0:
                    # 死细胞
                    count = 0
                    for dx, dy in [(-1, -1),
                                   (-1, 0),
                                   (-1, 1),
                                   (0, 1),
                                   (0, -1),
                                   (1, -1),
                                   (1, 0),
                                   (1, 1)]:
                        if 0 <= i + dx < m and 0 <= j + dy < n:
                            if board[i + dx][j + dy] in (1, 3):
                                count += 1
                    # 死细胞周围正好3个细胞，复活
                    if count == 3:
                        # 先设为2，等下再变回1
                        board[i][j] = 2
                if item == 1:
                    # 活细胞
                    count = 0
                    for dx, dy in [(-1, -1),
                                   (-1, 0),
                                   (-1, 1),
                                   (0, 1),
                                   (0, -1),
                                   (1, -1),
                                   (1, 0),
                                   (1, 1)]:
                        if 0 <= i + dx < m and 0 <= j + dy < n:
                            if board[i + dx][j + dy] in (1, 3):
                                count += 1
                    # 活细胞周围少于2，死亡
                    if count < 2:
                        # 先设为3，等下设置为0
                        board[i][j] = 3
                    elif count > 3:
                        board[i][j] = 3
                    else:
                        pass
        for i in range(m):
            for j in range(n):
                if board[i][j] == 3:
                    board[i][j] = 0
                if board[i][j] == 2:
                    board[i][j] = 1
        return
        
        
        

```