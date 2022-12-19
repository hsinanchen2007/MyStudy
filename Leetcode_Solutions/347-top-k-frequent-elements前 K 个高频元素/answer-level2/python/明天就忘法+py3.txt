### 解题思路
此处撰写解题思路

### 代码

```python3
from heapq import*
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        heap=[]
        dic={}
        ans=[]
        for i in range(len(nums)):
            # 统计每个元素的个数
            dic[nums[i]]=dic.get(nums[i],0)+1
        for key in dic.keys():
            # 进堆，默认小顶堆，所以大顶堆需要取反 
            # 输出也要记得添加负号
            heapq.heappush(heap,(-dic[key],key))
        while k:
            ans.append(heapq.heappop(heap)[1])
            k-=1
        return ans
```