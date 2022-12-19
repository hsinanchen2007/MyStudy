```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def findleft(start, end, target):
            if start > end : return end
            mid = (start + end) // 2
            if nums[mid] > target:
                return findleft(start, mid-1, target)
            elif nums[mid] < target:
                return findleft(mid+1, end, target )
            else:
                return findleft(start, mid-1, target)
        
        def findright(start, end, target):
            if start >end : return end
            mid = (start + end) // 2
            if nums[mid] > target:
                return findright(start, mid-1, target)
            elif nums[mid] < target:
                return findright(mid+1, end, target )
            else:
                return findright(mid+1, end, target)
        return findright(0, len(nums)-1, target) - findleft(0, len(nums)-1, target) 
```
