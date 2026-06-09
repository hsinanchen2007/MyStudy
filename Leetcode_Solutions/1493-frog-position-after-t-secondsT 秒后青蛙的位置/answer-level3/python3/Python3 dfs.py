先用defaultdict存储edge，然后自顶向下dfs，记录时间tt和概率p。到达target时，如果当前时间刚好是t，或者当前时间小于t并且target点之后无顶点，那么当前概率p有效，否则概率为0。
```
class Solution:
    ans = 0
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        from collections import defaultdict
        edges = [sorted(edge) for edge in edges]
        dic = defaultdict(list)
        for edge in edges:
            dic[edge[0]].append(edge[1])

        def dfs(node, p, tt):
            if node == target:
                if tt == t or (tt < t and not dic[node]):
                    self.ans = p
                else:
                    self.ans = 0
            if dic[node]:
                p /= len(dic[node])
                for post in dic[node]:
                    dfs(post, p, tt+1)

        dfs(1, 1, 0)
        return self.ans
```
