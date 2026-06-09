```
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i in range(len(numbers)):
            res = target - numbers[i]
            if numbers[i] in d:
                return [d[numbers[i]],i+1]
            else: 
                d[res] = i + 1
```