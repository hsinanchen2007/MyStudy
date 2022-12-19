首先先把图的邻接表存进字典，并且按字典序排序，然后从‘JFK’开始深搜，每前进一层就减去一条路径，直到某个起点不存在路径的时候就会跳出while循环进行回溯，相对先找不到路径的一定是放在相对后面，所以当前搜索的起点from会插在当前输出路径的第一个位置。

```py
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        d = collections.defaultdict(list)   #邻接表
        for f, t in tickets:
            d[f] += [t]         #路径存进邻接表
        for f in d:
            d[f].sort()         #邻接表排序
        ans = []
        def dfs(f):             #深搜函数
            while d[f]:
                dfs(d[f].pop(0))#路径检索
            ans.insert(0, f)    #放在最前
        dfs('JFK')
        return ans
```
