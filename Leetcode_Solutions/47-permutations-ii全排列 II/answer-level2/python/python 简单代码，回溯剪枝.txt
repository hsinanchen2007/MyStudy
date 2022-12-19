### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def permuteUnique(self, nums):
        # 先得到所有排列， 然后使用unique
        path=[]
        res=[]
        used=[]

        def traceback(nums,path):
            if not nums:
                res.append(path)
                return 
            for i in range(len(nums)):
                
                if i>0 and nums[i] in nums[:i]:  # 直接减枝, 前面只要用过这个数，在这一次循环就pass
                    continue
                
                traceback(nums[:i]+nums[i+1:],path+[nums[i]])

        traceback(nums,path)
        return res

        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
```