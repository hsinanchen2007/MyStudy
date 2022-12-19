基本思想：以每个人作为最低效率时，前k个最大速度的最大团队表现值
- 首先按每个人的效率降序排序，O(nlogn)；
- 将每个人的速度依次插入小根堆中，`add_sum`记录速度和
- 当插入第k+1个数时，`add_sum`记录前k大速度和当前堆中最小值，`add_sum`减去最小值，仍为前k个最大速度之和；
- 速度和乘以最低效率即为当前最大团队表现值；
- 又k<n，因此最终时间复杂度O(nlogn)


```python3
from queue import PriorityQueue
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        items = [(speed[i], efficiency[i]) for i in range(n)]
        items.sort(key=lambda item:item[1], reverse=True)
        add_sum = 0
        pq = PriorityQueue()
        res = 0
        for i in range(n):
            pq.put(items[i][0])
            add_sum += items[i][0]
            if pq.qsize() > k:
                add_sum -= pq.get()
            val = add_sum * items[i][1]
            if val > res:
                res = val
        return res % (10 ** 9 + 7)
```