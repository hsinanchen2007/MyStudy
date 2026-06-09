### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parent = {}
        def find(x):
            parent.setdefault(x,x)
            if x!=parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        def union(x,y):
            parent[find(y)] = find(x)
        res = []
        for a,b in edges:
            if find(a)==find(b):
                res.append(a)
                res.append(b)
            else:
                union(a,b)
        return res
        
```