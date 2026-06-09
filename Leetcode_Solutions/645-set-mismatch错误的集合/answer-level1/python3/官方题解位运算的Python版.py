### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findErrorNums(self, nums):
        xor = xor0 = xor1 = 0
        for n in nums:
            xor ^= n
        for i in range(1, len(nums) + 1):
            xor ^= i
        rightmostbit = xor & ~(xor - 1)
        for n in nums:
            if (n & rightmostbit) != 0:
                xor1 ^= n
            else:
                xor0 ^= n
        for i in range(1, len(nums) + 1):
            if (i & rightmostbit) != 0:
                xor1 ^= i
            else:
                xor0 ^= i
        for i in range(len(nums)):
            if nums[i] == xor0:
                return [xor0, xor1]
        return [xor1, xor0]
```