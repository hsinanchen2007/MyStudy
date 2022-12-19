![image.png](https://pic.leetcode-cn.com/8acd1c368ae2e8e282822355d46f7bc54f2cc3b28f766a9b6c71ff37a1156fe0-image.png)

应该是python3里最短最快的tarjan了，2332ms，100%，仅供参考。

因为题目给的条件就已经连通了，所以建好邻接表以后就没必要再遍历表了，随便找一个点作为递归起点就可以了。

```python []
class Solution:
    def criticalConnections(self, n, connections):
        ans, low, d = [], [-1] * n, [[] for _ in range(n)]
        for i, j in connections:
            d[i].append(j)
            d[j].append(i)
        def tarjan(c, v, p):
            dfn = low[v] = c
            for i in d[v]:
                if i != p:
                    if low[i] == -1: 
                        c += 1
                        tarjan(c, i, v)
                        if low[i] > dfn:
                            ans.append([v, i])
                    low[v] = min(low[v], low[i])
        tarjan(0, 0, -1)
        return ans
```
```python []
class Solution:
    def criticalConnections(self, n, connections):
        ans, low, d = [], [0] * n, [[] for _ in range(n)]
        for i, j in connections:
            d[i].append(j)
            d[j].append(i)
        def tarjan(c, v, p):
            dfn = low[v] = c
            for i in d[v]:
                if i != p:
                    if not low[i]: 
                        c += 1
                        tarjan(c, i, v)
                        low[i] > dfn and ans.append([v, i])
                    low[v] = min(low[v], low[i])
        return tarjan(1, 0, -1) or ans
```


之前比赛用的拓扑排序，显然算法层面来说是错的，虽然当时是AC了。
现在增加了用例，拓扑排序也直接AC不了了。