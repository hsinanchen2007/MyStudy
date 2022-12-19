
### 代码

```python3
class Solution:
    def initialize_tree(self, n):
        self.tree_num = n
        self.tree_node = [1]*(n+1)
        self.parent = [i for i in range(n+1)]
    def find(self, node):
        while node!= self.parent[node]:
            self.parent[node] = self.parent[self.parent[node]]
            node = self.parent[node]
        return node
    def union(self, i,j):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i == root_j:
            return
        # self.parent[root_i]=root_j
        if self.tree_node[root_i]>self.tree_node[root_j]:
            self.parent[root_j] = root_i
            self.tree_node[root_i]+=self.tree_node[root_j]
        else:
            self.parent[root_i] = root_j
            self.tree_node[root_j] +=self.tree_node[root_i]
    def findRedundantConnection(self, edges):
        if not edges:
            return []
        n = len(edges)
        self.initialize_tree(n)

        for i in range(1,n+1):
            if self.find(self.parent[edges[i-1][0]]) != self.find(self.parent[edges[i-1][1]]):
                self.union(edges[i-1][0], edges[i-1][1])
            else:
                return edges[i-1]
        return [0,0]


        
```