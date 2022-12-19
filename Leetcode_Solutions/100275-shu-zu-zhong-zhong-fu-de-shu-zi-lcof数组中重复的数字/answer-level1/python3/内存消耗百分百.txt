### 解题思路
书上给的思路

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        if nums:
            i = 0
            while i < len(nums):
                if nums[i] != i:
                    if nums[i] != nums[nums[i]]:
                        a = nums[i]
                        nums[i] = nums[nums[i]] 
                        nums[a] = a
                        i = i 
                        continue
                    else:
                        return nums[i]
                else:
                    i = i + 1
            if i == len(nums):
                return False
        else:
            return False
```