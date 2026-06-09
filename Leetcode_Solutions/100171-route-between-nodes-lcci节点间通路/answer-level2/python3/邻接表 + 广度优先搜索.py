
将题目给的邻接关系表示成邻接表，然后从start出发，依次搜索一度连接节点，二度连接节点（一度好友的一度好友），依此类推，如果target在这里邻接节点中，则返回TRUE；如果遍历完所有节点，也没有找到，则返回False。
```
class Solution:
    def findWhetherExistsPath(self, n: int, graph: List[List[int]], start: int, target: int) -> bool:
        link_table = [[] for _ in range(n)]
        for i, j in graph:
            link_table[i].append(j)
        curr = [start]
        next_node = []

        while curr:
            for node in curr:
                if target in link_table[node]:
                    return True
                next_node += link_table[node] 
            curr = next_node
            next_node = []
        return False

```
