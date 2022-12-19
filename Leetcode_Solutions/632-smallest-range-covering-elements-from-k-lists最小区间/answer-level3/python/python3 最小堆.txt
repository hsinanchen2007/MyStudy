### 解题思路
最小堆中确保存放 k 个序列中的每一个序列的一个数。
每次从堆中弹出一个数的时候，把这个数所对应的序列的下一个数存入，同时维护此时堆中的最小和最大值。
当弹出的数是对应序列的最后一个值的时候，跳出循环。

### 代码

```python3
import heapq
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        heap = []
        n = len(nums)
        mi = float('inf')
        ma = float('-inf')
        for i in range(n):
            heapq.heappush(heap, (nums[i][0], 0, i))
            mi = min(mi, nums[i][0])
            ma = max(ma, nums[i][0])
            
        res = [mi, ma]
        while True:
            cur = heapq.heappop(heap)
            if cur[1] == len(nums[cur[2]]) - 1:
                break
            heapq.heappush(heap, (nums[cur[2]][cur[1]+1], cur[1]+1, cur[2]))
            ma = max(ma, nums[cur[2]][cur[1]+1])
            mi = heap[0][0]
            if ma-mi < res[1]-res[0]:
                res = [mi, ma]
            elif ma-mi == res[1]-res[0] and mi < res[0]:
                res = [mi, ma]
        return res
```