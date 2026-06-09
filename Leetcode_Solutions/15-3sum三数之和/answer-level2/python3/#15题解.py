### 解题思路
先对数组进行排序，再控制一个数进行遍历，其余两个数依靠双指针进行寻找，注意重复解。

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        if not nums or len(nums)<3:
            return []
        lst=[]
        for i in range(len(nums)-2):
            if nums[i]>0:
                return lst
            #防止重复解
            if i>0 and nums[i]==nums[i-1]:
                continue
            l=i+1
            r=len(nums)-1
            while l<r:
                if nums[i]+nums[l]+nums[r]==0:
                    lst.append([nums[i],nums[l],nums[r]])
                    防止重复解
                    while l<r and nums[l]==nums[l+1]:
                        l+=1
                    while l<r and nums[r]==nums[r-1]:
                        r-=1
                    l+=1
                    r-=1
                elif nums[i]+nums[l]+nums[r]>0:
                    r-=1
                else:
                    l+=1
        return lst
                
                
                
                    
                
            
```