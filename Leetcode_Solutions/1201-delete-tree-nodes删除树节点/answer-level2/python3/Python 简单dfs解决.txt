

```
'''
构建树形结构
然后遍历树，找和为0子树，把子树节点全部打标记，最后
统计没有被打标记的节点个数
'''

from typing import List, Set
class Solution:

    def dfs(self, cur, child_map, value, flag) -> (int, List[int]):
        if cur not in child_map:
            if value[cur] == 0:
                flag[cur] = 0
            return (value[cur], [cur])

        total_sum = value[cur]
        total_nodes = [cur]
        for next in child_map[cur]:
            sum, nodes = self.dfs(next, child_map, value, flag)
            total_sum += sum
            total_nodes.extend(nodes)

        if total_sum == 0:
            for node in total_nodes:
                flag[node] = 0

        return (total_sum, total_nodes)


    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        child_map = {}
        for i in range(nodes):
            par, val = parent[i], value[i]
            if par not in child_map:
                child_map[par] = []
            child_map[par].append(i)

        flag = [1 for _ in range(nodes)]

        self.dfs(-1, child_map, value, flag)
        return sum(flag)
```
