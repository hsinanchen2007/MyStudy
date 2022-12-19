### 方法1：排序返回倒数第k个数
```python
return sorted(nums)[-k]
```
### 方法2：冒泡k次最大的数
```python
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # 冒泡k次
        for i in range(k):
            j =0 
            while j < len(nums)-1-i:
                if nums[j] > nums[j+1]:
                    nums[j] ,nums[j+1] = nums[j+1] , nums[j]
                j += 1
        return nums[-k]

```
### 方法3：构造一个k大的小顶堆
```python
import heapq
def kthLargestElement( k, nums):
    if len(nums) <k :
        return 
    nums_k = nums[0:k] 
    heapq.heapify(nums_k)
    for num in nums[k : len(nums) ]:
        item = max(num , heapq.heappop(nums_k))
        heapq.heappush(nums_k,item)
    return nums_k[0]
```







