```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        cnt = collections.Counter(nums)
        count = len(nums) / 3
        
        for k, v in cnt.items():
            if v > count:
                ans.append(k)
            
        return ans
```