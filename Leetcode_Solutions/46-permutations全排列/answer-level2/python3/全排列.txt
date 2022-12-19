```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) <= 1:
            return [nums]
        
        out =[]
        perms = self.permute(nums[1:])
        for perm in perms:  
            for i in range(len(perm)+1):
                p = perm[:i] + [nums[0]] + perm[i:]
                out.append(p)
        
        return out
            
```