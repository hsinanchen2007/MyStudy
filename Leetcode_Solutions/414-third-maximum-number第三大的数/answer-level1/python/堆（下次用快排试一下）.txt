### 解题思路
也可以用快排（没写明白……）
sorted()应该就是快排~但是还是想尝试自己写一下~下次写吧
### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        # Solution 1: x=[2,2,3,1]; y_pred=2; y_true=1
        import heapq
        nums = list(set(nums))
        heapq.heapify(nums)
        if len(nums) < 3: 
            return heapq.nlargest(len(nums), nums)[0]
        # else:
        while len(nums) > 3:
            heapq.heappop(nums)
        return nums[0]

        # Solution 2:
        # if len(nums) <= 1: return nums[0]
        # if len(nums) == 2: return [nums[1], nums[0]][nums[0] < nums[1]] 
        # idx = 0
        # while idx == len(nums)-1 or nums[i] <
        #     nums, idx = self.quicksort(nums, idx)
        #     if idx < 3:

        # def quicksort(self, nums, idx):
        #     new_idx = idx
        #     for i in range(idx+1, len(nums)):
        #         if nums[idx] > nums[i]:
        #             nums[i], nums[idx] = nums[idx], nums[i]
        #             new_idx = i
        #     return nums, new_idx
```