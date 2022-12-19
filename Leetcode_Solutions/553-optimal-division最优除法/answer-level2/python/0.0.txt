### 解题思路
此处撰写解题思路
肯定是数字越做除法就越小的
### 代码

```python3
class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        ans=''
        m=len(nums)
        if m==1:
            return str(nums[0])
        elif m==2:
            return str(nums[0])+'/'+str(nums[1])
        for i in range(len(nums)):
            if i ==0:
                ans =ans+str(nums[i])
            elif i==1:
                ans=ans+'/'+'('+str(nums[i])
            else:
                ans=ans+'/'+str(nums[i])
        ans=ans+')'
        print(ans)
        return ans
        
```