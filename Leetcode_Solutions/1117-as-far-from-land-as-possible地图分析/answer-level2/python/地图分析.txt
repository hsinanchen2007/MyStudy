### 解题思路
先找到grid中所有的1的位置，保存在queue中，若全是1或者没有1，返回-1
从这些1所在的位置开始进行广度优先搜索，即搜索四个方向，如果搜索的位置上的值为0，保存这些坐标，作为下一次搜索的起点，并将这些位置的值设置为1，以免重复搜索。这样每扩散一层，计数器加1，直到没有可搜索的起点，返回计数器的值就为最远的距离


### 代码

```python
class Solution(object):
    def maxDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        queue = [(i,j) for i in range(n) for j in range(n) if grid[i][j] == 1]
        if len(queue) == n * n or not queue: return -1
        level = 0
        while queue:
            t = []
            for x,y in queue:
                for i,j in [(x+1,y), (x-1, y), (x, y+1), (x, y-1)]:
                    if 0 <= i < n and 0 <= j < n and grid[i][j] == 0:
                        t.append((i, j))
                        grid[i][j] = 1
            queue = t
            level += 1
        return level-1
```