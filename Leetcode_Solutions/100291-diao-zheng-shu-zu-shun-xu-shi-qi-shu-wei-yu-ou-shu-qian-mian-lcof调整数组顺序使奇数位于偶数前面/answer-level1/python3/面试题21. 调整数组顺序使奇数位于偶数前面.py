### 双指针

```python []
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        l, r = 0, len(nums) - 1
        while l < r:
            if nums[l] & 1:
                l += 1
            elif ~ nums[r] & 1:
                r -= 1
            else:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
        return nums
```

### 排序

```python []
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        return sorted(nums, key=lambda x: ~ x & 1)
```