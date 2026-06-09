问题的关键是定位到pivot的位置。分情况进行讨论查找即可。

```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if not nums:
            return 0
        left = 0
        right = len(nums)-1
        while left < right:
            mid = (left + right) // 2
            if nums[left] > nums[mid]:
                # pivot located at left part
                right = mid
            elif nums[right] < nums[mid]:
                # pivot located at right part
                left = mid + 1
            else:
                if nums[left] == nums[mid] and nums[mid] == nums[right]:
                    # unable to locate the pivot, so traverse
                    min_v = nums[right]
                    for i in range(left, right):
                        min_v = min(min_v, nums[i])
                    return min_v
                elif nums[left] == nums[mid]:
                    # nums[mid] < nums[right], so min is located at left part.
                    # we cannot judge whether there is a pivot.
                    # so traverse the left part
                    min_v = nums[mid]
                    for i in range(left, mid):
                        min_v = min(min_v, nums[i])
                    return min_v
                elif nums[right] == nums[mid]:
                    # similar to the situation above
                    min_v = nums[left]
                    for i in range(mid, right+1):
                        min_v = min(min_v, nums[i])
                    return min_v
                else:
                    # nums[left] < nums[mid] < nums[right]
                    return nums[left]
        return nums[left]
```
