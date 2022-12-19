### 解题思路

两种方法，三种代码速度差不多，一种backtrack，一种postorder，一种直接sort，一种heapq
[Hierholzer算法](https://taodaling.github.io/blog/2019/04/25/Hierholzer%E7%AE%97%E6%B3%95/)
### 代码

```
from heapq import heappop, heappush
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        def _dfs(start):
            while dic[start]:
                _dfs(heappop(dic[start]))
            res.insert(0, start)
        dic = collections.defaultdict(list)
        for start, to in tickets:
            heappush(dic[start], to)
        res = []
        _dfs('JFK')
        return res

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:       
        def dfs(node):
            while dic[node]:
                dfs(dic[node].pop())
            res.append(node)           
       
        dic = collections.defaultdict(list)
        for i, j in sorted(tickets)[::-1]:
            dic[i].append(j)
        res = []
        dfs('JFK')
        return res[::-1]


from collections import defaultdict
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:

        graph = defaultdict(dict)

        for start, to in tickets:
            graph[start][to] = graph[start].get(to, 0)+1
        res = []
        def _dfs(cur, temp):
            nonlocal res
            if res!=[]:
                return 
            if len(temp)==len(tickets)+1:
                res.append(temp[:])
            
            for to in sorted(graph[cur].keys()):
                temp.append(to)
                graph[cur][to]-=1
                _dfs(to, temp)
                temp.pop()
                graph[cur][to]+=1
        
        _dfs('JFK', ['JFK'])
        return res   
```