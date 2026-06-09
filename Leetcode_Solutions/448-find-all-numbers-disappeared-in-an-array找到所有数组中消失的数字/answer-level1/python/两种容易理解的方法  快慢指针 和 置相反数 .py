**# 第一种 快慢指针：**
将数组中出现过的数减1作为下标，并将数组下标为该数的位置置为-1，最后统计不为-1的下标加1即为未出现的数
```
class Solution(object):
    def findDisappearedNumbers(self, nums):
        res=[]
        for i in range(len(nums)):
            if nums[i]!=-1:
                index=nums[i]
                while nums[index-1]!=-1 :
                    tmp=nums[index-1]
                    nums[index-1]=-1
                    index=tmp
        for i in range(len(nums)):
            if nums[i]!=-1:
                res.append(i+1)
        return res
```
# **第二种 置相反数：**
将数组中出现过的数减1作为下标，并将数组下标为该数的位置置为其相反数，最后统计为负数的下标加1即为未出现的数
```
class Solution(object):
    def findDisappearedNumbers(self, nums):
        res=[]
        for num in nums:
            index=abs(num)-1
            nums[index]=-abs(nums[index])
        for i in range(len(nums)):
            if nums[i]>0:
                res.append(i+1)
        return res
```
