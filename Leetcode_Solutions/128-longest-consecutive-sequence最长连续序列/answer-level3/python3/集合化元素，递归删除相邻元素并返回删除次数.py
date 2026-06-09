![image.png](https://pic.leetcode-cn.com/037d0b8435462a08a130864c09bcc2aabe32a2c8a133a1ea8073c63bab4813fc-image.png)

通俗易懂
```
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        d=set(nums)
        
        def f(i):
            if i in d:
                d.remove(i)
                return 1+f(i+1)+f(i-1)
            return 0
        
        ans=0
        for i in nums:
            ans=max(ans,f(i))
        
        return ans
```
