
```
class Solution:
    def canJump(self, nums: List[int]) -> bool:  #本质上是看0的前面 是否能够越过0
        L=len(nums)
        if L==1:
            return True
        for i in range(L-1,-1,-1):
            if nums[i]==0:
                if i==0:
                    return False
                for j in range(i-1,-1,-1):
                    if (i!= L-1 and j+nums[j]>i) or (i== L-1 and j+nums[j]>=i) :
                        break
                    if j==0:
                        return False  
            elif i==0:
                return True
        return True 
```
