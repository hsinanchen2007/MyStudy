# 解题思路
首先，我们需要记录2个状态，一个是player的位置，另一个是box的位置。
用DFS来判断player是否能推动box，用BFS来寻找box到目的地的最短路径。
具体做法:
1.先找到初始的box，player，end的位置。
2.创建一个队列Q, 将box，player的位置信息入队。
3.队列中的元素出队，并更新当前grid中box和player的位置信息。
4.用BFS搜索当前box的所有下一步合法位置，并用DFS来判断player能否到达能够推动box到下一步的位置。
5.将所有合法的状态入队。
6.重复步骤3-5，直到队列空或者box被推到了终点。
# 代码
```python3
from collections import deque
class Solution:
    def minPushBox(self, grid: list) -> int:
        box_visited = set()
        directions = [(-1,0),(1,0),(0,-1),(0,1)]
        player, box, end = None,None,None
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 'S':
                    player = (i,j)
                if grid[i][j] == 'B':
                    box = (i,j)
                if grid[i][j] == 'T':
                    end = (i,j)
                if player and box and end:
                    break
        # 箱子下一个位置是否合法
        def isValid(loc):
            if  (0 <= loc[0] < len(grid)) and (0 <= loc[1] < len(grid[0])):
                return False if (grid[loc[0]][loc[1]] == '#') else True
            return False
        # 玩家的下一个位置是否合法
        def isValid_player(loc):
            if  (0 <= loc[0] < len(grid)) and (0 <= loc[1] < len(grid[0])):
                return False if (grid[loc[0]][loc[1]] == '#' or grid[loc[0]][loc[1]] == 'B') else True
            return False


        # 玩家是否可以按照这个方向推当前位置的箱子
        def CanPush(box ,player, direction, visited):
            if (box[0] - direction[0] == player[0]) and (box[1] - direction[1] == player[1]):
                return True
            else:
                visited.add(player)
                for option in directions:
                    new_loc = (player[0]+option[0], player[1]+option[1])
                    if isValid_player(new_loc) and new_loc not in visited:
                        if CanPush(box, new_loc, direction, visited):
                            return True
                return False

        # BFS
        Q = deque()
        Q.append([box, player, 0])
        push_time = 0
        while len(Q) > 0 and box != end:
            box, player, push_time = Q.popleft()
            grid[box[0]][box[1]] = 'B'
            grid[player[0]][player[1]] = 'S'
            for direction in directions:
                new_box = (box[0] + direction[0], box[1] + direction[1])
                if isValid(new_box):
                    if (box, new_box) not in box_visited:
                        if CanPush(box, player, direction, set()):
                            box_visited.add((box, new_box))
                            new_player = (box[0],box[1])
                            Q.append([new_box, new_player, push_time+1])
            grid[box[0]][box[1]] = '.'
            grid[player[0]][player[1]] = '.'
        return push_time if box == end else -1
```
