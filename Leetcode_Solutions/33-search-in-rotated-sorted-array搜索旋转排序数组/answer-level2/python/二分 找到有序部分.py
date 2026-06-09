```
class Solution:
    def search(self, nums, target: int) -> int:
        if not nums: return -1 #解决问题的关键是找到无序数组的有序部分，从而进行二分查找
        #通过比较 nums[l] nums[r] nums[mid] 的大小关系 确定哪一段是有序的
        l,r=0,len(nums)-1
        while l<=r:
            mid = (l+r)//2
            if nums[r]==target: return r
            if nums[l]==target: return l
            if mid == r or mid==l: return -1
            if nums[l]>nums[r]:
                if nums[mid]<nums[r]:
                    if nums[mid]<target and nums[r]>target:
                        l = mid
                    else:
                        r  = mid
                else:
                    if nums[mid]>target and nums[l]<target:
                        r = mid
                    else:
                        l = mid
            else:
                if nums[mid]<target:
                    l = mid
                else:
                    r =mid
        return -1

nums = [4,5,6,7,8,1,2,3,4]
nums1 = [9]
target = 9
print(Solution().search(nums,target))
print(Solution().search(nums1,target))
```
