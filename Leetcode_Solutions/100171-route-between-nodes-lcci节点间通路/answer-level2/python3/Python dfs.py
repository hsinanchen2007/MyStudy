先用defauldict建立邻接表，然后dfs，其中使用visited判断当前点是否访问过
```
class Solution:
    def findWhetherExistsPath(self, n: int, graph: List[List[int]], start: int, target: int) -> bool:
        from collections import defaultdict
        dic = defaultdict(list)
        for g in graph:
            dic[g[0]].append(g[1])
        visted = [False] * n
        def dfs(vertex, visted):
            if vertex == target:
                return True
            if visted[vertex]:
                return False
            visted[vertex] = True
            ans = False
            for post in dic[vertex]:
                ans = ans or dfs(post, visted)
            return ans
        return dfs(start, visted)
```
