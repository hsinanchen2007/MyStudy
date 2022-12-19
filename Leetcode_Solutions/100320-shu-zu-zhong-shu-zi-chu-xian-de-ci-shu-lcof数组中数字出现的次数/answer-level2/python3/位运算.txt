### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        res = 0
        for i in range(len(nums)):
            res ^= nums[i]
        ind = 1
        while res & ind == 0:
            ind <<= 1
        a,b = 0,0
        for i in range(len(nums)):
            if (nums[i] & ind == 0):a ^= nums[i]
            else:b ^= nums[i]
        return [a,b]
```