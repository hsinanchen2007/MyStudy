### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0: return [[]]
        result = [[nums[0]], []]

        for i in range(1, len(nums)):
            temp = []
            for value in result:
                temp.append(value + [nums[i]])
            result.extend(temp)
        return result


```