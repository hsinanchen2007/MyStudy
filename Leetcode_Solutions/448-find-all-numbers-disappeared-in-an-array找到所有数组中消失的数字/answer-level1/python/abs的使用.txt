### 解题思路
巧妙使用abs，遍历已存在的下标

### 代码

```python3
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        
        for i in range(len(nums)):
            #防止下一次遍历到负数的时候，找不到下标[4,3,2,7,8,2,3,1]
            loc=abs(nums[i])-1
            if nums[loc]>0:
                nums[loc]=-nums[loc]
                #[4,3,2,-7,8,2,3,1]
            #print(nums)
            #[-4, -3, -2, -7, 8, 2, -3, -1]
        #i从1开始赋值
        res=[]
        for i,v in enumerate(nums,1):
            if v>0:
                res.append(i)
        return res



            


        
```