```
class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        num2 = 2 * nums
        stack = []
        res = [-1 for _ in num2]
        for index in range(len(num2)):
            while stack and num2[index] > num2[stack[-1]]:
                res[stack.pop()] = num2[index]
            stack.append(index)
        return res[:len(nums)]
```
这样看是多行了么？