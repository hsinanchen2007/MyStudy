```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left,right = 0,len(nums) - 1
        if nums[left] <= nums[right]:
            return nums[0]
        else:
            while left < right:
                pivot = (left + right) // 2
                if nums[pivot] > nums[pivot + 1]:
                    return nums[pivot + 1]
                else:
                    if nums[pivot] < nums[right]:
                        right = pivot
                    else:
                        left = pivot 
        return nums[pivot]
```
- 时间复杂度：O(log N)使用了二分查找。
- 空间复杂度：O(1)