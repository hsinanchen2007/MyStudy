```
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        #先变成有序数组
        cut = -1
        for i in range(len(nums)-1):
            if nums[i]>nums[i+1]:
                cut=i
                break
        if cut!=-1:
            nums = nums[i+1:]+nums[:i+1]
        #二分查找
        low = 0 
        high = len(nums)-1
        mid = (low+high)//2
        while low<=high:
            if nums[mid]==target:
                break
            else:
                if nums[mid]<target:
                    low = mid+1
                    mid = (low+high)//2
                else:
                    high = mid-1
                    mid = (low+high)//2
        if 0<=mid<len(nums) and nums[mid]==target:
            return True
        else:
            return False
                    
                    
            
```
