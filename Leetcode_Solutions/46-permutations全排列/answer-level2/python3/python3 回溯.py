```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
    
        def helper(strs):
            if len(strs) == len(nums):
                res.append(strs)
                return   
            for i in nums:
                if i not in used:            
                    used.add(i)
                    helper(strs + [i])
                    used.remove(i)
                    
        res, used = [], set()
        helper([])
        return res
```
