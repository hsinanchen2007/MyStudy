普通：
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low=0
        high=len(nums)-1
        while low<=high:
            mid=low+(high-low)//2
            if nums[mid]<target:
                low=mid+1
            elif nums[mid]>target:
                high=mid-1
            elif nums[mid]==target:
                return mid
        return -1
```
递归：
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low=0
        high=len(nums)-1
        def bisect(lt,low,high,target):
            if low>high:
                return -1
            mid=low+(high-low)//2
            if lt[mid]<target:
                return bisect(lt,low+1,high,target)
            elif lt[mid]>target:
                return bisect(lt,low,high-1,target)
            elif lt[mid]==target:
                return mid
        return bisect(nums,low,high,target)
```






