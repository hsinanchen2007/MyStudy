```
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        f=[0]*len(nums)
        for n in nums:
            f[n-1]+=1
        for i in range(len(nums)):
            if f[i]==0:
                a=i+1
            elif f[i]==2:
                b=i+1
        return [b,a]
```
