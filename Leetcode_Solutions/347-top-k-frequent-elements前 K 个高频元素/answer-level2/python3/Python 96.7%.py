第一步：hash统计次数（在Python中要巧用字典）
第二步：字典键值对压入大顶堆（注意如何将heapq小顶堆作为大顶堆使用）
第三步：大顶堆吐出k个值加入返回list



代码：
```
import heapq


class Solution:
    def topKFrequent(self, nums, k):
        heap_max = []
        dic_fre = {}
        ans = []
        for i in nums:
            if i in dic_fre:
                dic_fre[i]+=1
            else:
                dic_fre[i] = 1
        for i in dic_fre:
            heapq.heappush(heap_max,(-dic_fre[i],i))
        for j in range(k):
            p = heapq.heappop(heap_max)
            ans.append(p[1])
        return ans

```