### 解题思路
二分法。

主要考虑l == r时情况。

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:

        def binary(nums, l, r):
            if l == r:
                if target > nums[l]:
                    return r+1
                else:
                    return r
            mid = (l+r) // 2
            if target > nums[mid]:
                ii = binary(nums, mid+1, r)
            elif target < nums[mid]:
                ii = binary(nums, l, mid)
            else:
                ii = mid
            return ii
        
        if not nums:
            return 0
        l, r = 0, len(nums)-1
        insert = binary(nums, l, r)
        return insert

        
```