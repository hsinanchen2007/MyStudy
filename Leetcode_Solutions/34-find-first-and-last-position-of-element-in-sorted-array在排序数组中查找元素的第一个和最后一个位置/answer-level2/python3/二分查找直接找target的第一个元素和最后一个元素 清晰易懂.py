class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums or target>nums[-1] or target<nums[0]:return [-1,-1]
        if len(nums)==1:return [0,0] if nums[0]==target else [-1,-1]
        low,high=0,len(nums)-1
        start,end=-1,-1
        while low<high:                         #查找第一个target位置也就是第一个不小于target的元素
            mid=(low+high)>>1
            if nums[mid]<target:low=mid+1
            else:high=mid
        if nums[low]==target:start=low          #如果target在数组内才给start赋值
        low,high=0,len(nums)-1
        while low<high:                         #查找最后一个target位置也就是最后一个不大于target的元素
            mid=(low+high+1)>>1
            if nums[mid]>target:high=mid-1      
            else:low=mid
        if nums[high]==target:end=high          #如果target在数组内才给end赋值
        return [start,end]

