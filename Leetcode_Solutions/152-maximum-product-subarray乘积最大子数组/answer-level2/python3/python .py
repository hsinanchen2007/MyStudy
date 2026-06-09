DP:
```
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = [{"max":nums[0], "min":nums[0]},]
        
        for i in range(1,len(nums)):
            if nums[i]>=0:
                _max = max(res[i-1]['max']*nums[i],nums[i])
                _min = min(res[i-1]['min']*nums[i],nums[i])
            else:
                _max = max(res[i-1]['min']*nums[i],nums[i])
                _min = min(res[i-1]['max']*nums[i],nums[i])
            res.append({"max":_max,"min":_min})
        return max([item["max"] for item in res])
```
