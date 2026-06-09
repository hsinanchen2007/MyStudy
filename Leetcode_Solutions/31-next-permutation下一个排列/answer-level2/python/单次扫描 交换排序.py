```
class Solution:
    def nextPermutation(self, nums) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 2 4 3 1 
        # 1 一遍扫描，从后往前扫描直到发现不在递增，找到了，定位left；找不到left=-1，调到3
        # 2 从数组末尾遍历，找到第一个大于nums[left]的位置right, swap(nums[left],nums[right])
        # 3 双指针交换排序(利用数列的有序性质)
        if len(nums)==1: return
        l,r = len(nums)-2, len(nums)-1
        
        while l>-1 and nums[l]>=nums[l+1]:
            l-=1
        
        if l>-1:
            while nums[l]>=nums[r] and r>l:
                r-=1
            nums[l],nums[r]=nums[r],nums[l]
        
        left,right = l+1,len(nums)-1
        while left<right:
            nums[left],nums[right]=nums[right],nums[left]
            left+=1
            right-=1
            
        return nums
print(Solution().nextPermutation([5,2,3,2,0]))
```
