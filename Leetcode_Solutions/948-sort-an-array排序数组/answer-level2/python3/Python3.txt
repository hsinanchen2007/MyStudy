### 解题思路


### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # 3. 堆排
        import heapq
        res, minHeap = [], []
        for i in nums:
            heapq.heappush(minHeap, i)
        while minHeap:
            res.append(heapq.heappop(minHeap))
        return res
        
        # 2. 归并
#         def merge(numsA, numsB, la, ra, lb, rb):
#             k, tmp = 0, [0] * (ra - la + 1 + rb - lb + 1)
#             while la <= ra and lb <= rb:
#                 if numsA[la] <= numsB[lb]:
#                     tmp[k] = numsA[la]
#                     la += 1
#                 else:
#                     tmp[k] = numsB[lb]
#                     lb += 1
#                 k += 1
#             while la <= ra:
#                 tmp[k] = numsA[la]
#                 la, k = la + 1, k + 1
#             while lb <= rb:
#                 tmp[k] = numsB[lb]
#                 lb, k = lb + 1, k + 1
#             return tmp
            
#         def mergeSort(nums, l, r):
#             if l == r:
#                 return nums
#             mid = (l + r) // 2
#             mergeSort(nums, l, mid)
#             mergeSort(nums, mid+1, r)
#             nums[l:r+1] = merge(nums, nums, l, mid, mid+1, r)
#             return nums
        
#         return mergeSort(nums, 0, len(nums)-1)
        
        # 1. 快排
#         import random
#         def randomSelect(nums, l, r):
#             pivot = random.randint(l, r)
#             nums[l], nums[pivot] = nums[pivot], nums[l]
            
#         def partition(nums, l, r):
#             if l > r:
#                 return
            
#             pivot = nums[l]
#             while l < r:
#                 while l < r and nums[r] > pivot:
#                     r -= 1
#                 nums[l] = nums[r]
#                 while l < r and nums[l] <= pivot:
#                     l += 1
#                 nums[r] = nums[l]
#             nums[l] = pivot
#             return l      
        
#         def quickSort(nums, l, r):
#             if l > r:
#                 return
#             randomSelect(nums, l, r)
#             mid = partition(nums, l, r)
#             quickSort(nums, l, mid - 1)
#             quickSort(nums, mid + 1, r)
#             return nums
        
#         return quickSort(nums, 0, len(nums)-1)
            
            
```