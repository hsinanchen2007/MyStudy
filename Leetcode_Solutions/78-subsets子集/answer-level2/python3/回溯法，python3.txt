```
class Solution:
    def subsets(self, nums):
        res = [[]]
        def backtrack(nums,index):
            if len(nums) == 0:
                return
            for i in range(index,len(nums)):
                res.append(nums[:i+1])
                backtrack(nums[:i] + nums[i+1:],i)
                
        backtrack(nums,0)
        return res
```
自己捣鼓了一下，不知道咋通过了，好像效率不是很高？
