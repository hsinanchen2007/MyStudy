


class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        i=0
        list1=[]
        while i<len(nums)/2:
            a,b=nums[2*i],nums[2*i+1]
            for j in range(1,a+1):
                list1.append(b)
            i=i+1 
        return list1
```