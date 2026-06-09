并查集标准模板。找到环跳出循环直接返回即可。
```
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        def find_root(node, parent):
            node_root = node
            while parent[node_root] != -1:
                node_root = parent[node_root]
            return node_root
        def union(x, y, parent):
            x_root = find_root(x, parent)
            y_root = find_root(y, parent)
            if x_root == y_root:
                return [x, y]
            else:
                parent[x_root] = y_root
                return [-1, -1]
        l = len(edges)
        parent = [-1] * (l+1)
        for i in range(l):
            x = edges[i][0]
            y = edges[i][1]
            if union(x, y, parent) != [-1, -1]:
                return union(x, y, parent)
```
