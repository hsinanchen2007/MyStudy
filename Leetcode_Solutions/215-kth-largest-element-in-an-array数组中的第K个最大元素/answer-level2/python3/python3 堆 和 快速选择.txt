### 解题思路
此处撰写解题思路

### 堆

```python
from heapq import *
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # 小顶堆，剩k个最大的元素，去堆顶最小即为第k大元素
        # heap = []
        # for n in nums:
        #     heappush(heap, n)
        #     if len(heap) > k:
        #         heappop(heap)

        # return heappop(heap)

        #一句写法
        return nlargest(k, nums)[-1]
```
### 快速选择

```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        def partition(left, right, pivot_index):
            pivot = nums[pivot_index]

            nums[pivot_index], nums[right] = nums[right], nums[pivot_index]

            store_index = left
            for i in range(left, right):
                if nums[i] < pivot:
                    nums[store_index], nums[i] = nums[i], nums[store_index]
                    store_index += 1

            nums[store_index], nums[right] = nums[right], nums[store_index]

            return store_index

        def select(left, right, k_smallest):
            if left == right:
                return nums[left]
            
            pivot_index = random.randint(left, right)

            pivot_index = partition(left, right, pivot_index)

            if k_smallest == pivot_index:
                return nums[k_smallest]
            elif k_smallest < pivot_index:
                return select(left, pivot_index - 1, k_smallest)
            else:
                return select(pivot_index + 1, right, k_smallest)

        return select(0, len(nums) - 1, len(nums) - k)
```