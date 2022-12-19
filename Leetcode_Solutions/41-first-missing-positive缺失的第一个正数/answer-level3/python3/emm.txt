```
class Solution:
    #受到统计数组中的数的次数的启发
    def firstMissingPositive(self, nums):
        n = len(nums)
        if 1 not in nums:
            return 1
        if n == 1:
            return 2
        
        for i in range(n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = 1
        i = 0
        while i<n:
            temp = nums[i]-1
            if temp<0:
                i+=1
                continue
            if nums[temp]>0:
                nums[i] = nums[temp]
                nums[temp] = -1
            else:
                nums[i] = 0
                nums[temp] -=1
        flag = 0
        for i in range(n):
            if nums[i]==0:
                flag = 1
                break
        return  i+1 if flag ==1 else i+1+1
        
        


```
