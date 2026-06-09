### 解题思路
1. 生成一个由工资和质量的比率从小到大的排好顺序的列表
2. 遍历排好顺序的列表，根据质量存入到最大堆里
3. 求出长度为K的最大堆的成本

### 代码

```python3
import heapq

class Solution:
    def _mincostToHireWorkers(self, quality: List[int], wage: List[int], K: int) -> float:
        h = []
        wq = list(zip(wage, quality))
        wq = sorted(wq, key=lambda x: x[0] / x[1])
        print('wq: ', wq)
        res = float('inf')
        sumq = 0
        for w, q in wq:
            heapq.heappush(h, (-q, w))
            sumq += q
            if len(h) == K:
                res = min(res, w/q * sumq)
                q1, _ = heapq.heappop(h)
                sumq += q1
        return res
    
    def mincostToHireWorkers(self, quality, wage, K):
        pq = []
        wq = [(1.0 * w/q, q) for w, q in zip(wage, quality)]
        wq.sort()
        res = float('inf')
        sumq = 0
        for r, q in wq:
            heapq.heappush(pq, -q)
            sumq += q
            if len(pq) == K:
                res = min(res, r * sumq)
                q1 = heapq.heappop(pq)
                sumq += q1
        return res
                
```