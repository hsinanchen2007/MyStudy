```python
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        length = len(nums)
        if length == 1:
            return [nums]
        
        result = []
        for i in range(length):
            cur = nums[i]
            leftNums = nums[:i] + nums[i+1:]
            leftPerm = self.permute(leftNums)
            for item in leftPerm:
                item.insert(0, cur)
                result.append(item)

        return result
```
