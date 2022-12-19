这是个普通方法，没有使用原地算法。
### 解题思路
因为面板上的格子需要同时更新，所以我们不能一个个的来更新格子，需要使用一个新的数组，来存储其初始状态。
### 代码

```python
class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        if len(board) == 0:
            return board
        m = len(board)
        n = len(board[0])
        import copy
        res = copy.deepcopy(board)#此处需要深拷贝
        directions = [[0, 1], [0, -1], [-1, 0], [1, 0], [-1, -1], [-1, 1], [1, -1], [1, 1]]
        res.insert(0, [0] * (n + 2))#将新数组扩展，这样就不用考虑数组越界了。
        res.append([0] * (n + 2))
        for i in range(1, m + 1):
            res[i].insert(0, 0)
            res[i].append(0)
        for i in range(m):
            for j in range(n):
                t = 0#统计周围的活细胞数目
                for d in directions:
                    t += res[i + 1 + d[0]][j + 1 + d[1]]
                if board[i][j] == 0:
                    if t == 3:
                        board[i][j] = 1
                else:
                    if t < 2 or t > 3:
                        board[i][j] = 0
```