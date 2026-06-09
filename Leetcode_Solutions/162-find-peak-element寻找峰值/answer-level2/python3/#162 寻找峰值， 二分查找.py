### 解题思路
时间复杂度：O(log(n))
空间复杂度：O(1)

和有序数组的二分查找一样，只不过加一个每一步判断l，r，mid对应的位置是不是峰值，最好情况时间复杂度可以是O(1)。
### 代码

```python3
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0

        l, r = 0, len(nums) - 1
        
        while l < r:
            mid = (l + r) // 2
            if nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]:
                return mid
            if nums[l] > nums[l + 1] and (l == 0 or nums[l] > nums[l - 1]):
                return l
            if nums[r] > nums[r - 1] and (r == len(nums) - 1 or nums[r] > nums[r + 1]):
                return r
            if nums[mid] < nums[mid + 1]:
                l = mid + 1
            else:
                r = mid - 1
```