```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        if len(nums) < 1:
            return [-1,-1]
        
        # 1.线性扫描；先从左往右，再从右往左
        # 时间复杂度: O(n)
        
        # 2.二分查找 
        # 分别查找边界: [)
        # 1)查找左边界
        l, r = 0, len(nums)
        while(l<r):
            mid = l + (r-l)//2 # 避免溢出
            if nums[mid] == target:
                r = mid
            elif nums[mid] < target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid 
        
        if l >= len(nums) or l < 0 or nums[l] != target:
            return [-1,-1]
        ll = l
        # 2)查找右边界
        l, r = 0, len(nums)
        while l < r:
            mid = l + (r-l)//2
            if nums[mid] == target:
                l = mid + 1
            elif nums[mid] < target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid
        
        if r-1 >= len(nums) or r-1 < 0 or nums[r-1] != target:
            return [-1,-1]
        
        return [ll, r-1]
```
