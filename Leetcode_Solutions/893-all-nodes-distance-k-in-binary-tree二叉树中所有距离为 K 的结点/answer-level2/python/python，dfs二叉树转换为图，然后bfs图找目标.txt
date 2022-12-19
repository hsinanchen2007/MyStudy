
```python
    def distanceK(self, root, target, K):
        if not K:  # k为0时即target自己，不用构造图
            return [target.val]
        def dfs(root):
            for i in (root.left, root.right):
                if i:
                    graph[root.val] = graph.get(root.val, set()) | {i.val}
                    graph[i.val] = {root.val}
                    dfs(i)
        # 通过dfs构造图
        graph = {}
        dfs(root)
        # 通过bfs找目标
        q = [(target.val, 0)]
        res = []
        visited = set()
        while q:
            node, dist = q.pop(0)
            if node not in visited:
                if dist == K:
                    res.append(node)
                else:
                    visited.add(node)
                    for i in graph.get(node, ()):
                        q.append((i, dist + 1))
        return res
```
