```python
from typing import List
import collections
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        connect = collections.defaultdict(list)
        memo = collections.defaultdict(int)
        for ticket in tickets:
            connect[ticket[0]].append(ticket[1])
            memo[(ticket[0], ticket[1])] += 1
        for c in connect.values():
            c.sort()

        res = []
        def dfs(city, edge_num, tempArr):
            nonlocal res
            if res != []:  return
            if edge_num == len(tickets):
                res = tempArr[:]
                return
            for neibor in connect[city]:
                if memo[(city, neibor)] > 0:
                    tempArr.append(neibor)
                    memo[(city, neibor)] -= 1
                    dfs(neibor, edge_num + 1, tempArr)
                    tempArr.pop()
                    memo[(city, neibor)] += 1
        dfs('JFK', 0, ['JFK'])
        return res

```