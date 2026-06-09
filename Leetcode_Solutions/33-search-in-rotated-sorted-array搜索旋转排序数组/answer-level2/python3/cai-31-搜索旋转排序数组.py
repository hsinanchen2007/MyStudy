### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binarysearch(nums):
            n = len(nums)
            p, r = 0, n
            while p < r:
                mid = p + (r - p) // 2
                if nums[mid] == target: return mid
                elif nums[mid] > target:r = mid
                else:p = mid + 1
            return -1

        def searchindex(nums):
            n = len(nums)
            p, r = 0, n
            while p < r:
                mid = p + (r - p) // 2
                if nums[mid] > nums[0]:p = mid + 1
                else:
                    if nums[mid] < nums[mid - 1]:
                        return mid
                    else:
                        r = mid
            return -1
        d = searchindex(nums)
        if d == -1:return binarysearch(nums)
        if target == nums[0]:return 0
        elif target > nums[0]:return binarysearch(nums[:d])
        else:
            f = binarysearch(nums[d:])
            if f == -1:
                return -1
            else:
                return f + d
```