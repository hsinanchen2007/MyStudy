### 解题思路
用并查集去union每一对边的两个节点，如果一条边两个端点的父节点相同，那么这条边就可以删掉

### 代码

```python3
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        N = max([max(i) for i in edges])
        parent = [-1]+[i for i in range(1, N+1)]
        rank = [1 for i in parent]

        def find(x):
            if x == parent[x]:
                return x
            else:
                return find(parent[x])
        
        def union(x, y):
            xroot = find(x)
            yroot = find(y)
            if xroot != yroot:
                if rank[xroot] > rank[yroot]:
                    parent[yroot] = xroot
                else:
                    parent[xroot] = yroot
                    rank[yroot] += 1
        
        def union_find():
            for line in edges:
                if find(line[0]) == find(line[1]):
                    return line
                else:
                    union(line[0], line[1])
        
        return union_find()
```