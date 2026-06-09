

```

'''
员工信息组织成树形结构，
问题转化成求取树的根节点到叶子节点的最长带权路径长度
'''

from typing import List
from queue import Queue
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        m = {}
        for child, par in enumerate(manager):
            if par not in m:
                m[par] = []
            m[par].append(child)

        for id, next_list in m.items():
            max_val = max([informTime[id] for id in next_list])
            m[id] = [id for id in next_list if informTime[id] == max_val]

        que = Queue()
        que.put((headID, 0))

        max_len = 0
        while not que.empty():
            id, payload = que.get()

            if id not in m:
                max_len = max(max_len, payload)
            else:
                for next in m[id]:
                    que.put((next, payload + informTime[id]))

        return max_len

```
