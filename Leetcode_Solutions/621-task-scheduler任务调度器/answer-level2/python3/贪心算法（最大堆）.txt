### 解题思路
首先执行个数多的任务，当任务不够时填充！

### 代码

```python3
from heapq import heappush, heapify, heappop

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        if not tasks:
            return

        d = {}
        for c in tasks:
            d[c] = d.get(c, 0) + 1

        heap = [[-i, c] for c, i in d.items()]
        heapify(heap)

        times = 0

        while heap:
            count=min(n+1, len(heap))
            l=[]
            for _ in range(count): #在堆中取任务
                node=heappop(heap)
                if node[0]!=-1:
                    node[0]+=1
                    l.append(node) 
            for node in l:  #将未执行完的任务放回堆中
                heappush(heap, node)
            if heap:
                times+=n+1
            else:
                times+=count
        return times

```