### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        lens = len(nums)
        res = []
        for i in range(lens-2):
            k = i
            if nums[k] > 0: break
            if k>0 and nums[k-1]==nums[k]:continue
            l, r = k+1, lens-1
            while l<r:
                if nums[k]+nums[l]+nums[r]==0 :
                    res = res + [[nums[k], nums[l], nums[r]]]
                    l += 1
                    r -= 1
                    while l<r and nums[l]==nums[l-1]:
                        l += 1
                    while l<r and nums[r]==nums[r+1]:
                        r -= 1
                elif nums[k]+nums[l]+nums[r]>0:
                    r -= 1
                    while l<r and nums[r] == nums[r + 1]:
                        r -= 1
                else:
                    l += 1
                    while l<r and nums[l] == nums[l - 1]:
                        l += 1
        return res
```