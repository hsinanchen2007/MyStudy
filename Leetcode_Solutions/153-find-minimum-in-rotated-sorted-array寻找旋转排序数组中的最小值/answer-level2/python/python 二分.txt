### 解题思路
mid的可能性有两种nums[mid] < nums[r]，nums[mid] > nums[r]，
第一种情况说明最小元素在0-mid之间，包括mid，
二种情况说明最小元素在mid之后不包括mid。

### 代码

```python3
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        l = 0
        r = n-1
        while l<r:
            mid = l+(r-l)//2
            if nums[mid] < nums[r]:
                r = mid 
            else:
                l = mid + 1
        return nums[l]
```