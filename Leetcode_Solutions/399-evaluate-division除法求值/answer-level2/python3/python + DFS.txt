```python
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        if equations == []: return []
        adj = collections.defaultdict(list)
        value_dic = collections.defaultdict(int)
        visited = set()
    
        for i in range(len(equations)):
            x, y = equations[i]
            adj[x].append(y)
            adj[y].append(x)
            value_dic[(x, y)] = values[i]
            value_dic[(y, x)] = 1 / values[i]

        def dfs(node, val, visited):
            nonlocal y, y_val
            visited.add(node)
            if node == y: 
                y_val = val
                return
            for ch in adj[node]:
                if ch not in visited:
                    dfs(ch, val / value_dic[(ch, node)], visited)
        res = []
        for x, y in queries:
            if x in adj and y in adj :
                visited.clear()
                y_val = 0
                dfs(x, 1, visited)
                if y_val != 0: res.append(y_val)
                else: res.append(-1)
            else:
                res.append(-1)
        return res    
```