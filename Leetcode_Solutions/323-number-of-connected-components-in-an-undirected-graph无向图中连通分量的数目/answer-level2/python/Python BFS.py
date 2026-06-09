```
class Solution(object):
    def countComponents(self, n, edges):
        dic = collections.defaultdict(list)  # 用value默认为list的字典构图，时间复杂度最差情况为O(N^2)
        for e in edges:
            dic[e[0]].append(e[1])
            dic[e[1]].append(e[0])
            
        visited = set()
        res = 0
        # BFS整个图，遍历时间复杂度为O(2N),遍历所有无论visited或没visited的node一次，每个node再被初次visited一次。
        for i in range(n):
            if i not in visited:
                res += 1
                q = [i]
                visited.add(i)
                while q:  # 每一次完整的BFS代表着一个连通分量的完全遍历，res += 1
                    now = q.pop(0)
                    for n in dic[now]:
                        if n not in visited:
                            visited.add(n)
                            q.append(n)
        return res  # 遍历结束输出res即为所求
```
