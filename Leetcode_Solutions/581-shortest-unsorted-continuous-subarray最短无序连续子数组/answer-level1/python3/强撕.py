

### 代码

```python3
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        nums_ = sorted(nums)
        i = 0
        while nums[i] == nums_[i]:
            i += 1
            if i == len(nums):
                return 0
        j = len(nums)-1
        while nums[j] == nums_[j]:
            j -= 1
        return j-i+1
```