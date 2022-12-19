```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        l, r = 0, len(nums) - 1
        k = len(nums) - k
        while l <= r :
            pivot = self.findPivot(l, r, nums)
            if pivot == k: return nums[pivot]
            elif pivot < k: 
                l = pivot + 1
            else: r = pivot - 1

    def findPivot(self, l, r, nums):
        randomIndex = random.randint(l, r)
        nums[l], nums[randomIndex] = nums[randomIndex], nums[l]
        pivotVal = nums[l]
        while l < r:
            while l < r and nums[r] >= pivotVal : r -= 1
            nums[r], nums[l] = nums[l], nums[r]
            while l < r and nums[l] <= pivotVal:  l += 1
            nums[l], nums[r] = nums[r], nums[l]
        return l
```