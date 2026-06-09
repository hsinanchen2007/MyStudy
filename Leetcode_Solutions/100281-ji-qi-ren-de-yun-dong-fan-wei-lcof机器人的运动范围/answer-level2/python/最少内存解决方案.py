### 解题思路

使用广度优先搜索方案解答
### 代码

```python3
from collections import deque
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        count = 1
        search = deque()
        search.append((0,0))
        view = {}
        view[(0,0)] = None

        while search:
            (x,y) = search.popleft()
            path = []
            if x != 0:
                path.append((x-1,y))
            if y != 0:
                path.append((x,y-1))
            if x != n-1:
                path.append((x+1,y))
            if y != m-1:
                path.append((x,y+1))

            for p in path:
                if p not in view:
                    sx,sy = p
                    list_p = list(str(sx))+list(str(sy))
                    sum_p = sum(int(s) for s in list_p)
                    if sum_p <= k:
                        count+=1
                        view[p] = (x, y)
                        search.append(p)
        return count

```