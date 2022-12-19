```python []
import sys
from collections import deque

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        flights_dict = {}
        for lst in flights:
            lst_tmp = flights_dict.get(lst[0],[])
            lst_tmp.append(lst)
            flights_dict[lst[0]] = lst_tmp
        max_deps = K + 1
        min_pri = sys.maxsize
        deps = -1
        serach_deque = deque()
        serach_deque.append(Node(0, src))

        while serach_deque:
            deps += 1
            size = serach_deque.__len__()
            for i in range(0, size):
                node = serach_deque.popleft()
                if deps <= max_deps:
                    if node.index == dst:
                        min_pri = min(node.pri,min_pri)
                    else:
                        if deps < max_deps and node.pri < min_pri:
                            for lst in flights_dict.get(node.index, []):
                                if lst[2] + node.pri < min_pri:
                                    serach_deque.append(Node(lst[2] + node.pri, lst[1]))
        if min_pri == sys.maxsize:
            return -1
        else:
            return min_pri

class Node:
    def __init__(self, pri, index):
        self.pri = pri
        self.index = index
```
