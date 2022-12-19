### 解题思路
有两个地方要跳过

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n=len(nums)
        res=[]
        print(nums)
        for i in range(n-2):
            #跳过
            if i>0 and nums[i]==nums[i-1]:
                continue
            left=i+1
            right=n-1
            while left<right:
                
                t=nums[i]+nums[left]+nums[right]
                if t==0:
                    res.append([nums[i],nums[left],nums[right]])
                    print(i,left,right)
                    #跳过
                    while left<right and nums[left]==nums[left+1]:
                        left+=1
                    while left<right and nums[right]==nums[right-1]:
                        right-=1
                    left+=1
                    right-=1
                elif t>0:
                    right-=1
                else:
                    left+=1
        return res
```