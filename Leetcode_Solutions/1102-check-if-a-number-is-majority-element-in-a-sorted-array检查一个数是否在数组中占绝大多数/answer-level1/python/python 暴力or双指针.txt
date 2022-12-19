思路1：暴力哈希表
```
class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        dic = {}
        for i in nums:
            dic[i] = dic.get(i,0)+1
        
        if target not in dic: return False
        else:
            if dic[target]>len(nums)//2: return True
            else: return False
```
思路2：既然是有序的就要利用起来，双指针
```
class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        left,right = 0, len(nums)-1
        if len(nums)==1: return nums[0]==target
        while left<right:
            if nums[left]<target: left+=1
            if nums[left]>target: return False
            if nums[right]>target: right-=1
            if nums[right]<target: return False
            if nums[left]==nums[right]==target: break
        return right-left+1>len(nums)//2
```
