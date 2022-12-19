### 解题思路
思路比较简单，注意去除重复，现排序，i从的取值【0，n-2】 j的取值[i+1,n-1],k的取值[n,j+1]
如果nums[i]+nums[j]+nums[k]==0,加入res。大于零，后面的指针k前移，小于零，前面的指针j后移
如果nums[i]==nums[i-1]，continue，因为当nums[i]已经遍历过了，它会包括所有nums[i-1]的答案

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
       
        nums.sort()
        n=len(nums)
        if not nums or n < 3:
            return [] 
        res=[]
        for i in range(n-2):
            if i>=1 and nums[i]==nums[i-1]:
                continue
            j=i+1
            k=n-1
            tmp= nums[i]+nums[i+1]+nums[i+2]
            if tmp>0:
                return res
            while j<k:
                s=nums[i]+nums[j]+nums[k]
                if s ==0:
                    res.append([nums[i],nums[j],nums[k]])
                    j+=1
                    k-=1
                    while  j<k and nums[j]==nums[j-1]:
                        j+=1
                    while j<k and nums[k]==nums[k+1] :
                        k-=1
                elif  s>0:
                    k-=1
                else:
                    j+=1
        return res


```