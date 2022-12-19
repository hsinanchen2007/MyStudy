### 解题思路
此处撰写解题思路

### 代码

```python3
import numpy

class Solution:
    
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        self.matrix = matrix
        self.hight = len(matrix)
        if self.hight == 0:
            return []
        self.width = len(matrix[0])
        self.pa_walk = [[0]*self.width for _ in range(self.hight)]
        self.at_walk = [[0]*self.width for _ in range(self.hight)]
        pa_up = [(0, y) for y in range(self.width)]
        pa_le = [(x, 0) for x in range(self.hight)]
        at_do = [(self.hight-1, y) for y in range(self.width)]
        at_ri = [(x, self.width-1) for x in range(self.hight)]
        for co in pa_up:
            self.search(co, 'pa')
        for co in pa_le:
            self.search(co, 'pa')
        for co in at_do:
            self.search(co, 'at')
        for co in at_ri:
            self.search(co, 'at')
        # print(self.pa_walk)
        # print(self.at_walk)
        result = []
        for x in range(self.hight):
            for y in range(self.width):
                if self.pa_walk[x][y] == 1 and self.at_walk[x][y] == 1:
                    result.append([x, y])
        return result

    def __init__(self):
        self.matrix = None
        self.hight = 0
        self.width = 0
        # 上下左右
        self.directions = [(1,0), (-1,0), (0,-1), (0,1)]

    def try_step(self, coo):
        cur_val = self.matrix[coo[0]][coo[1]]
        rt_list = []
        # 向下
        down = [coo[0]+1, coo[1]] if coo[0]+1 < self.hight else None
        # 向上
        up = [coo[0]-1, coo[1]] if coo[0]-1 >= 0 else None
        # 向左
        left = [coo[0], coo[1]-1] if coo[1]-1 >= 0 else None
        # 向右
        right = [coo[0], coo[1]+1] if coo[1]+1 < self.width else None
        for x in [down, up, left, right]:
            if x is not None and cur_val <= self.matrix[x[0]][x[1]]:
                rt_list.append(x)
        return rt_list

    def legal(self, x, y):
        return 0 <= x < self.hight and 0 <= y < self.width

    def search(self, coordinate, ocen):
        x = coordinate[0]
        y = coordinate[1]
        if ocen == 'pa':
            if self.pa_walk[x][y] == 1:
                return
            else:
                self.pa_walk[x][y] = 1
        if ocen == 'at':
            if self.at_walk[x][y] == 1:
                return
            else:
                self.at_walk[x][y] = 1
        # try 4 direction
        for d in self.directions:
            new_x = x + d[0]
            new_y = y + d[1]
            # check available
            if self.legal(new_x, new_y):
                if self.matrix[x][y] > self.matrix[new_x][new_y]:
                    continue
                else:
                    self.search((new_x, new_y), ocen)

```