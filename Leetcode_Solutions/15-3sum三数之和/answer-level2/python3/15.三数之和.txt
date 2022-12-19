```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)
        if not nums or length<3:
            return []
        res = []
        nums.sort()
        for i in range(length):
            if nums[i] > 0:
                return res
            if(i>0 and nums[i]==nums[i-1]):
                continue
            k = i + 1
            j = length-1
            while k<j:
                sum = nums[k]+nums[i]+nums[j]
                if sum==0:
                    res.append([nums[i],nums[k],nums[j]])
                    while k<j and nums[k]==nums[k+1]:
                        k = k + 1
                    while k<j and nums[j]==nums[j-1]:
                        j=j-1
                    j=j-1
                    k=k+1
                elif(sum>0):
                    j = j - 1
                elif(sum<0):
                    k = k + 1

        return res
```
