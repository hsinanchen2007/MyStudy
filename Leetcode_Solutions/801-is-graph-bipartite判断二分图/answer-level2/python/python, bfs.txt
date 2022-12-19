```python
    def isBipartite(self, graph: List[List[int]]) -> bool:
        graph = {i: set(v) for i, v in enumerate(graph)}  # 通过set构造图
        parts = [set(), set()]  # 储存两部分所包含的当前结点
        notVisited = set(range(len(graph)))  # 当前未分配部分的结点
        while notVisited:
            q = [(notVisited.pop(), False)]  # 分配其到部分1，并用队列bfs
            while q:
                node, part = q.pop()
                notVisited.discard(node)  # 移除该未分配结点
                if node in parts[not part]:  # 如果该结点在另一部分已存在
                    return False  # 返回False
                parts[part].add(node)  # 否则加入该部分
                for next in graph[node]:  # bfs
                    if next not in parts[not part]:  # 将还未属于另一部分的结点加入队列
                        q.append((next, not part))
        return True
```
