### 解题思路
1. 组间拓扑排序
2. 组内拓扑排序
3. 拼接结果

### 代码

```python
from collections import defaultdict

def topsort(grid):
    count = {u:0 for u in grid}
    for u in grid:
        for v in grid[u]:
            count[v] += 1

    queue = [u for u in grid if count[u] == 0]
    ans = []
    while queue:
        u = queue.pop()
        ans.append(u)

        for v in grid[u]:
            count[v] -= 1
            if count[v] == 0:
                queue.append(v)
    return ans

class Solution(object):
    def sortItems(self, n, m, group, beforeItems):
        """
        :type n: int
        :type m: int
        :type group: List[int]
        :type beforeItems: List[List[int]]
        :rtype: List[int]
        """
        item_grids = {}
        group_grid = defaultdict(set)
        for i in range(n):
            if group[i] == -1:
                group[i] = m
                m += 1

            if group[i] not in item_grids:
                item_grids[group[i]] = defaultdict(list)

            if i not in item_grids[group[i]]:
                item_grids[group[i]][i] = []

            if group[i] not in group_grid:
                group_grid[group[i]] = set()

        for i in range(n):
            for j in beforeItems[i]:
                if group[i] == group[j]:
                    item_grids[group[i]][j].append(i)
                else:
                    group_grid[group[j]].add(group[i])

        ans = []
        groups_order = topsort(group_grid)
        for i in groups_order:
            item_grid = item_grids.get(i)
            if not item_grid:
                continue

            items_order = topsort(item_grid)
            if len(items_order) != len(item_grid):
                return []

            ans.extend(items_order)

        return ans if len(ans) == n else []
```