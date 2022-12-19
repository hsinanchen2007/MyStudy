### 解题思路
用两个指针分别指向连续子数组的左边界和右边界：`l, r = 0， 0`；

1. 先右移`r`，直到`sum(nums[l:r])>s`，然后再右移`l`，直到`sum(nums[l:r])<s`；
2. 重复步骤1直到`r>=len(nums)`；将这个过程中满足条件的最短连续子数组长度记录下来；

### 代码

```python3
class Solution:
    """
    双指针：l指向左边界，r指向右边界；
    """
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if s <= 0:
            return 1
        
        res = len(nums)+1
        l, r, tmp = 0, 0, 0
        while r < len(nums):
            while r<len(nums) and tmp < s:
                tmp += nums[r]
                r += 1
            while tmp >= s:
                res = r-l if r-l < res else res
                tmp -= nums[l]
                l += 1
        if res > len(nums):
            return 0
        else:
            return res
```