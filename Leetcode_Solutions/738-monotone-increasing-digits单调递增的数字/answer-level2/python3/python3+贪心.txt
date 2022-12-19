### 解题思路
从前往后找到第一个不符合要求的位数，然后该位减一，后面的都变成9，再从头判断，执行整个过程，直到满足要求

### 代码

```python3
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        nums = list(str(N))
        i = 0
        end = len(nums)
        while i < len(nums)-1:
            if nums[i] <= nums[i+1]:
                i += 1
            else:
                nums[i] = str(int(nums[i])-1)
                nums[i+1:end] = ['9'] * (end - i - 1)
                end = i+1
                i = 0
        return int(''.join(nums))
```