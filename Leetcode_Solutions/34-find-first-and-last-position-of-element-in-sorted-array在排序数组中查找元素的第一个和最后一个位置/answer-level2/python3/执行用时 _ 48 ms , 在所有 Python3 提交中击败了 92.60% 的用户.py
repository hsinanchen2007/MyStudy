利用两次二分查找，分别查找左右边界点。时间复杂度O（logn）
```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums)==0:
            return [-1,-1]
        if len(nums)==1:  
            return [0,0] if nums[0] == target else [-1,-1]
        low = 0
        high = len(nums)-1
        left = 0
        right = len(nums)  
        while low < high:
            mid = (low+high)//2
            if nums[mid] == target:
                high = mid     
            elif nums[mid] < target:
                low = mid + 1
            elif nums[mid] > target:
                high = mid
        one = low if nums[low] == target else -1
        while left < right:
            mid = (left+right)//2
            if nums[mid] == target:
                left = mid + 1
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid
        two = left-1 if nums[left-1] == target else -1
        return [one,two]
```
