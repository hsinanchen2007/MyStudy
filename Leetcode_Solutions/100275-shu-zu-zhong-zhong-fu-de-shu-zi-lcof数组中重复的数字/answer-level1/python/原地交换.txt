### 解题思路

对于每个位置，每次把当前所在的元素送到他应在的位置，直到找到属于该位置的那个，继续往下

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        
        n = len(nums)
        for i in range(n):

            while (nums[i] != i):
                tn = nums[i]
                if nums[tn] == tn:
                    return tn
                nums[i], nums[tn] = nums[tn], nums[i]
            
```