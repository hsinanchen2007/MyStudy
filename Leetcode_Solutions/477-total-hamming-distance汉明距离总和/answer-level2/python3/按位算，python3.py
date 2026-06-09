重在思想，各位之间的距离互不影响～
```
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        N=len(nums)
        res=0
        for i in range(32):
            n=0     #末位为1的数字量
            for num in nums:
                if (num>>i)&1:
                    n+=1             
            res+=n*(N-n)    #倒数第i位上，每个带0的和全部带1的产生n的距离
        return res
```
