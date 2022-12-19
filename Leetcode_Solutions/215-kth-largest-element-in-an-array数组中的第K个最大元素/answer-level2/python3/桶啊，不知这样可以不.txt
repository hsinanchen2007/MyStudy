```
class Solution(object):
    def findKthLargest(self, nums, k):
        max1 = max(nums)
        min1 = min(nums)
        k = len(nums)-k+1
        if min1<0:
            res = [0]*(max1-min1+1)
            for i in nums:
                res[i-min1] +=1 
            sum1 = 0 
            for i,j in enumerate(res):
                if sum1+j>=k:
                    return i+min1
                else:
                    sum1+=j
        else:
            res = [0]*(max1+1)
            for i in nums:
                res[i] +=1
            sum1= 0
            for i,j in enumerate(res):
                if sum1+j>=k:
                    return i
                else:
                    sum1+=j
            
    
```
