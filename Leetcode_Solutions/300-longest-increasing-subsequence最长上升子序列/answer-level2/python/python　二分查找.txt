### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def helper(nums,target):
            left,right=0,len(nums)-1
            while left<right:
                mid=left+(right-left)//2
                if nums[mid]<target:
                    left=mid+1
                elif nums[mid]>target:
                    right=mid
                else:
                    return mid
            return left

        if not nums:
            return 0
        res=[nums[0]]
        for i in range(1,len(nums)):
            if nums[i]>res[-1]:
                res.append(nums[i])
            else:
                index=helper(res,nums[i])
                res[index]=nums[i]
        return len(res)
```