### 解题思路
此处撰写解题思路
1. 主要是实现快排
### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def sort(nums, l, r):
            val = nums[l]
            while l < r:
                while l < r and nums[r] >= val:
                    r -= 1
                if l < r:
                    nums[l] = nums[r]
                    l += 1
                while l < r and nums[l] <= val:
                    l += 1
                if l < r:
                    nums[r] = nums[l]
                    r -= 1
            nums[l] = val
            return l
        def help(nums, l, r, k):
            dp = sort(nums, l, r)
            if dp == k:
                return
            elif dp > k:
                help(nums, l, dp-1, k)
            else:
                help(nums, dp+1, r, k)
        n = len(nums)
        if n < 1:
            return nums[k]
        help(nums, 0, n-1, n-k)
        return nums[n-k]
```