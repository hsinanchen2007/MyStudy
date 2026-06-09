其实也就只比第33题多一个步骤就可以了，就是验证左右节点是否相等，若相等，则左指针往右移一步即可。还有一点小区别就是`nums[mid] >= nums[left]`，要加上等于号，注意下这点即可。
```python []
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        if not nums:
            return False

        left,right = 0, len(nums)-1
        
        while left <= right:
            mid = left + (right-left)//2
            if nums[mid] == target or nums[right] == target or nums[left] == target:
                    return True
            if nums[left] != nums[right]:
                if nums[mid] >= nums[left]:
                    if nums[mid] > target and nums[left] < target:
                        right = mid - 1
                    else:
                        left = mid + 1
                elif nums[mid] <= nums[right]:
                    if nums[mid] < target and nums[right] > target:
                        left = mid + 1
                    else:
                        right = mid - 1
            else:
                left += 1

        return False
```