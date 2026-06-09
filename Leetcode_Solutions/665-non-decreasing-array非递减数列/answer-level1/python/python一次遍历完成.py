### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums)<3:
            return True
        index=0
        tmp=0
        for i in range(len(nums)-1):
            if nums[i]>nums[i+1]:
                index=i
                tmp+=1
            if tmp>1:
                return False
        if index==0 or index==len(nums)-2:
            return True 
        if nums[index-1]<nums[index+1] or nums[index]<nums[index+2]:
            return True
        return False
```