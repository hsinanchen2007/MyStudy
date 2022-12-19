![image.png](https://pic.leetcode-cn.com/d2366f08104b438d11aabe63d4087d829fe632fb612c88bedcef43ca765295b7-image.png)


```

'''
统计独占所在行和所在列的主机，所有主机减去独占的主机就是至少能
和一台其他主机通信的主机
'''


from typing import List
from collections import Counter
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        rows, cols = Counter(), Counter()
        pos = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    rows[i] += 1
                    cols[j] += 1
                    pos.append((i, j))

        ans = len(pos)
        for i, j in pos:
            if rows[i] == 1 and cols[j] == 1:
                ans -= 1
        return ans
```
