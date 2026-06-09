```
class Solution:
    def findMin(self, nums: List[int]) -> int:     
        n = len(nums)
        left, right = 0, n-1
        while nums[left] >= nums[right] and left < right:
            mid = (left + right) // 2
            if nums[left] <= nums[mid] and nums[mid] > nums[right]:
                left = mid + 1
            elif nums[left] > nums[mid] and nums[mid] <= nums[right]:
                right = mid
            else:
                right -= 1
        
        return nums[left]

```
当left指针所对应当值小于right指针所对应值时候跳出循环。
当nums[left] == nums[right] == nums[mid]时，将right指针向左移动一个单位。