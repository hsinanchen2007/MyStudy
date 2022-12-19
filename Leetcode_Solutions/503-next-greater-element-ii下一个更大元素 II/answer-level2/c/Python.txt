### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = [-1 for _ in range(len(nums))]
        stack = []
        for i in range(2 * len(nums) - 1,-1,-1):
            while (stack!=[] and nums[stack[-1]] <= nums[i % len(nums)]):
                stack.pop()
            if stack!=[]:
                res[i % len(nums)] = nums[stack[-1]]
            stack.append(i % len(nums))
        return res

```