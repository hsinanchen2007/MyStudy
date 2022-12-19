```
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums=sorted(nums)
        res=[]
        last=True
        for i in range(len(nums)-2):

            if nums[i]!=last:

                sum=-nums[i]
                for item in self.findTwosum(nums[i+1:],sum):
                    res.append([nums[i]]+item)
                last=nums[i]
        # print res
        return res
    def findTwosum(self,nums,sum):
        left =0
        right=len(nums)-1
        res=[]
        while left<right:
            if nums[right]+nums[left]==sum:
                if [nums[left],nums[right]] not in res:
                    res.append([nums[left],nums[right]])
                left+=1
            elif nums[right]+nums[left]>sum:
                right-=1
            else:
                left+=1
        # print nums, sum, res
        return res

```
