```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first_last = []
        left, right = 0, len(nums)-1
        
        #寻找左端点
        while left <= right:
            mid = (left + right)>>1
            
            if nums[mid] == target:
                if mid == 0 or nums[mid-1] < target:
                    first_last.append(mid)
                right = mid -1
            elif nums[mid] > target:
                right = mid -1
            elif nums[mid] < target:
                left = mid + 1
        
        #寻找右端点        
        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left + right)>>1
            
            if nums[mid] == target:
                if mid == len(nums)-1 or target < nums[mid + 1]:
                    first_last.append(mid)
                left = mid + 1
            elif nums[mid] > target:
                right = mid -1
            elif nums[mid] < target:
                left = mid + 1
        if first_last != []:
            return first_last
        else:
            return [-1,-1]
```

