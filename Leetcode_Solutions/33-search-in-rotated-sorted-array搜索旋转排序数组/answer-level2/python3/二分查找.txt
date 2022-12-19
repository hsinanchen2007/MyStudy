做法差不多 先找到旋转的index 然后判断属于哪一个区间 分别二分查找即可
```
#
# @lc app=leetcode.cn id=33 lang=python3
#
# [33] 搜索旋转排序数组
#
class Solution:
    def search(self, nums:List[int], target: int) -> int:
        if not nums or len(nums)<2:
            try:
                return nums.index(target)
            except :
                return -1
        for i in range(0,len(nums)-1):
            if nums[i]>nums[i+1]:
                break
        start_index=0 if target in nums[0:i+1] else i+1
        if start_index==0:
            left,end=0,i
            while left<=end:
                mid=(left+end)//2
                if nums[mid]==target:
                    return mid
                elif nums[mid]>target:
                    end-=1
                else:
                    left+=1
            return -1
        else:
            left,end=i+1,len(nums)-1
            while left<=end:
                mid=(left+end)//2
                if nums[mid]==target:
                    return mid
                elif nums[mid]>target:
                    end-=1
                else:
                    left+=1
            return -1
```