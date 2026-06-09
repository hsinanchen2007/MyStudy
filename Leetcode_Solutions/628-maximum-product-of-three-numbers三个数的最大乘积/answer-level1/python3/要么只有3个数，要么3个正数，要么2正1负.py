```
class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums.__len__()==3:
            return nums[0]*nums[1]*nums[2]
        nums_sm=[]
        nums_bg=[]
        for i in range(nums.__len__()):
            if nums[i]<0:
                nums_sm.append(nums[i])
            else:
                nums_bg.append(nums[i])
        nums_sm=sorted(nums_sm)
        nums_bg=sorted(nums_bg)
        rs=[]
        if nums_bg.__len__()>=3:
            rs.append(nums_bg[-1]*nums_bg[-2]*nums_bg[-3])
        if nums_sm.__len__()>=2 and nums_bg.__len__()>=1:
            rs.append(nums_sm[0]*nums_sm[1]*nums_bg[-1])
        return max(rs)
```
