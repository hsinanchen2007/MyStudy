```
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def check(nums,new):
            for i in range(len(nums)):
                if abs(new-nums[i]) in (0,len(nums)-i):
                    return False
            return True
        mapping,ans = ['.'*i + 'Q' + '.'*(n-i-1) for i in range(n)],[]        
        def backtrack(nums):
            if len(nums)==n:
                ans.append([mapping[c] for c in nums])
                return 
            for i in range(n):
                if check(nums,i):
                    backtrack(nums+[i])
        backtrack([])
        return ans
 
```