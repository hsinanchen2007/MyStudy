```
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        
        nums = [1]
        next = []
        for i in range(1, n):
            k = 0
            for j in range(len(nums)):
                if j+1>=len(nums) or nums[j] != nums[j+1]:
                    next += [j-k+1, nums[k]]
                    k = j+1
            nums = next
            next = []
        return ''.join(map(str, nums))
                
```
