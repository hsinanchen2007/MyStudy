### 解题思路
每个陆地离自己的距离为0，所以虽然陆地不是连续的，但它们都位于0的层次

### 代码

```python3
from collections import deque
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        N = len(grid)
        steps = [(-1,0),(0,-1),(1,0),(0,1)]

        def bps(deque1,marked,templen):
            while deque1:
                length = len(deque1)
                for index in range(length):
                    x,y = deque1.pop()
                    #print(x,y)
                    for s_x,s_y in steps:
                        nextx,nexty = x+s_x, y+s_y
                        if -1<nextx<N and -1<nexty<N and (nextx, nexty) not in marked:
                            marked.add((nextx,nexty))
                            if grid[nextx][nexty]==0:
                                deque1.appendleft((nextx,nexty))
                templen += 1
            return templen 
        list1 = []
        for subr in range(N):
            for subc in range(N):
                if grid[subr][subc] == 1:
                    list1.append((subr,subc))
        deque1 = deque(list1)

        temp = bps(deque1,set(),-1)

        if temp==0:
            temp=-1
        return temp
```