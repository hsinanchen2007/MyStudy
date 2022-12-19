解法：
思路一，存储target-nums的每个元素
思路二，存储nums中的每个元素
```
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # 存储target-nums的每个元素
        dict1 = {}
        for i in range(len(nums)):
            if nums[i] in dict1:
                return [dict1.get(nums[i]), i]
            dict1[target - nums[i]] = i

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # 存储nums中的每个元素
        dict1 = {}
        for i in range(len(nums)):
            value = target - nums[i]
            if value in dict1:
                return [dict1.get(value), i]
            dict1[nums[i]] = i
```
