### 解题思路
首先二分法找到第一个相等值的下标
找到下标后直接左右移动搜索

### 代码

```python
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        n=len(nums)
        if n==1:
            if nums[0]==target:
                return [0,0]
            else:
                return [-1,-1]

        left=0
        right=n-1
        #找到第一个相等的值
        ind=-1
        while left<=right:
            mid=(right+left)//2
            if nums[mid]==target:
                ind=mid
                break
            elif nums[mid]>target:
                right=mid-1
            else:
                left=mid+1
        if ind==-1:
            return [-1,-1]

        res_l=ind
        while res_l>0 and nums[res_l]==nums[res_l-1]:
            res_l-=1
        
        res_r=ind
        while res_r<n-1 and nums[res_r]==nums[res_r+1]:
            res_r+=1
        
        return[res_l,res_r]




        


```