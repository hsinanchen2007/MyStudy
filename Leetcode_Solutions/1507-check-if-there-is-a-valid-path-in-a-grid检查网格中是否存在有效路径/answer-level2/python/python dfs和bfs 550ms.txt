```
from collections import deque


HAS_RIGHT = {1, 4, 6}
HAS_LEFT = {1, 3, 5}
HAS_DOWN = {2, 3, 4}
HAS_TOP = {2, 5, 6}


MOVE_DICT = {1: [(1, 0), (-1, 0)], 2: [(0, 1), (0, -1)], 
             3: [(-1, 0), (0, 1)], 4: [(1, 0), (0, 1)],
             5: [(-1, 0), (0, -1)], 6: [(1, 0), (0, -1)]}
CHECK_MATCH = {(0, 1): HAS_TOP, (1, 0): HAS_LEFT, (0, -1): HAS_DOWN, (-1, 0): HAS_RIGHT}


def next_position(p, move, visited, max_row, max_col, grid):
    row, col = p
    mr, mc = move
    row2 = row + mc
    col2 = col + mr
    if row2 >= max_row or col2 >= max_col or row2 < 0 or col2 < 0:
        return None

    rev = (row2, col2)

    if rev in visited:
        return None

    if grid[row2][col2] in CHECK_MATCH[move]:
        return rev
    return None


class Solution(object):
    def hasValidPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        max_col = len(grid[0])
        max_row = len(grid)
        visited = set()
        s = [(0, 0)]
        # s = deque([(0, 0)])

        while s:
            p = s.pop()
            # p = s.popleft()
            if p[0] == max_row - 1 and p[1] == max_col - 1:
                return True

            for move in MOVE_DICT[grid[p[0]][p[1]]]:
                next_p = next_position(p, move, visited, max_row, max_col, grid)
                if next_p is not None:
                    visited.add(next_p)
                    s.append(next_p)

        return False

```
dfs和bfs就是用stack和queue的区别。

简化版的题目就是：全0全1的grid，0表示不通1表示通，判断(0,0)到(r-1, c-1)是不是可达。
这题目就是要把 下一个位置放入栈（或者队列）的条件变一下。

开头定义了四个常量，HAS_RIGHT表示 这个格子上的路有没有到右边的通路（其他三个同理）
MOVE_DICT是根据当前格子的类型，得到要移动的方向。如：路径1就是[(1, 0), (-1, 0)]表示只能往左右走。
CHECK_MATCH是用来判断：到达当前点的move方式和当前点的类型是不是匹配的。

ps:有点烦，最开始用xy来表示位置，然后发现行列总是要在脑子里咯一下，就把xy改成了row,col。
pps:不过MOVE_DICT懒得改了，所以正常来讲[1,0]应该表示向下走，我这里是表示向右走。所以这段很奇怪
```
    row, col = p
    mr, mc = move
    row2 = row + mc
    col2 = col + mr
```
