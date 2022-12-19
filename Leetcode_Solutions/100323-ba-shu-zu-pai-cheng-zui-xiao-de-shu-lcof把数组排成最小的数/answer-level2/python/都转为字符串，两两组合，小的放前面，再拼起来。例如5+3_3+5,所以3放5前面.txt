### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def minNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        n=len(nums)
        if n==0:
            return ""
        for i in range(n):
            nums[i]=str(nums[i])
        for i in range(n):
            for j in range(i+1,n):
                if nums[i]+nums[j]>nums[j]+nums[i]:
                    nums[i],nums[j]=nums[j],nums[i]
        return "".join(nums)
```