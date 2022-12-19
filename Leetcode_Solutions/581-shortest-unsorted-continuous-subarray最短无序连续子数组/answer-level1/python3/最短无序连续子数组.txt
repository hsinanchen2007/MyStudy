### 解题思路
排序，然后进行比较即可

### 代码

```python3
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        nums_copy = sorted(nums)
        L = 0
        R = len(nums) - 1
        while(L < len(nums)):
            if nums[L] == nums_copy[L]:
                L += 1
            else:
                break
        while(R > 0):
            if nums[R] == nums_copy[R]:
                R -= 1
            else:
                break
        if L <= R:
            return R - L + 1
        else:
            return 0
```