```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        num = len(nums) // 3
        num_tmp = list(set(nums))
        result = []
        for i in range(len(num_tmp)):
            if nums.count(num_tmp[i]) > num and num_tmp[i] not in result:
                result.append(num_tmp[i])
        return result
```
