### 解题思路
此处撰写解题思路

### 代码

```python3
import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        #堆来实现 大顶堆
        heap=[]
        ans=0
      
        for num in nums:
            #构造大顶堆，heapq模块默认小顶堆 所以需要取反 
            # 取出元素时也需要取反
            heapq.heappush(heap,-num)
        while k-1:
            heapq.heappop(heap)
            k-=1
        #返回值要加负号
        return -heapq.heappop(heap)




```