## 思路

主要思想是遍历，如何定义问题，可以使得前面问题的解决对于后面问题保留了很多信息。

将人按照效率从高到底排序，子问题是0-i个人中选择的解
当加入第i+1个人之后，计算前i+1个人的速度的最大的k个和，和当前加入的人的效率进行比较，如果大于维护的最大值，则更新。

1. k个最大的人包含了第i+1个人，那么算法正确定得到了保证
2. 前k最大的人不包含第i+1个人，那么得到的结果就不会大于前面的维护的结果，正确性也得到了保证

**使用堆来维护访问过的人中前k个最大的**

## 代码

```python
import heapq

class Solution:
    def maxPerformance(self, n: int, speed, efficiency, k: int) -> int:
        # 将所有成员按照效率逆序排序，然后遍历
        record = [[speed[i], efficiency[i]] for i in range(n)]
        record.sort(key=lambda x :x[1], reverse=True)
        heap = []
        temp_sum = 0
        max_ = float('-inf')
        for i in range(n):
            temp_sum += record[i][0]
            heapq.heappush(heap, record[i][0])
            if len(heap) <= k:
                max_ = max(temp_sum*record[i][1], max_)
            else:
                item = heapq.heappop(heap)
                temp_sum -= item
                max_ = max(temp_sum * record[i][1], max_)
        return max_ % (1000000007)
```