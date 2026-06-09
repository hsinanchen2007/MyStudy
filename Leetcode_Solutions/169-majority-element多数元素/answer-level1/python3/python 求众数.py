# 方法一 需要一个列表存储元素
```
class Solution(object):
    def majorityElement(self, nums):
        list_1=[]
        n=len(nums)
        for i in range(n//2+1):
            if nums[i]  in list_1:
                i+=1
                continue
            else :
                list_1.append(nums[i])
                if nums.count(nums[i])>n//2:
                    return nums[i]
```
方法二 排序后找中位数
```
class Solution(object):
    def majorityElement(self,nums):
        nums.sort()
        return nums[len(nums)//2]
```
方法三 摩尔投票算法
```
class Solution(object):
    def majorityElement(self,nums): 
        tmp=nums[0]
        count=1
        for i in range(1,len(nums)):
            if count==0:
                tmp=nums[i]
            count=count+1 if nums[i]==tmp else count-1
        return tmp
```