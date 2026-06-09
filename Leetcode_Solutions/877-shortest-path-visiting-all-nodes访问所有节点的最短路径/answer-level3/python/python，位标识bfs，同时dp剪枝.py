跟大家一样用二进制表示已访问的结点的记录。用了dp做剪枝。
```python
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        target = (1 << n) - 1  # 目标即全部已访问
        dp = [[float('inf')] * n for _ in range(target+1)]  # dp[i][j]：走到j结点且已访问记录为i时的当前最小步数
        for i in range(n):
            dp[1 << i][i] = 0  # 初始化所有起点的dp为0
        q = [(1 << i, i) for i in range(n)]  # BFS状态队列：（已访问记录，当前位置）
        while q:
            visited, at = q.pop(0)
            if visited == target:  # 达到目标
                return dp[visited][at]
            step = dp[visited][at] + 1  # 下一步的步数
            for next in graph[at]:  # 访问邻居
                _visited = visited | (1 << next)  # 走出该步后的新访问记录
                if step < dp[_visited][next]:  # 如果比以前更快达到该状态
                    dp[_visited][next] = step  # 更新dp
                    q.append((_visited, next))  # 入队BFS
        return -1  # 不存在这样的路径
```
