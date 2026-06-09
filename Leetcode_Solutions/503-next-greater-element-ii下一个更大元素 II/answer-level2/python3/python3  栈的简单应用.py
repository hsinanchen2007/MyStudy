第一步，找到最大的元素，先从最大元素开始逆序遍历到0，将这些元素按逆序存进栈中。

第二步，从数组nums中逆序遍历，一次比较当前元素和栈顶元素大小，更新对应元素下一个更大元素， 栈中维持逆序序列
```py3
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        mx = -2 ** 32
        idx = -1
        res = [-1] * len(nums)
        stack = []
        for i, num in enumerate(nums):
            if mx < num:
                mx = num
                idx = i 
        for i in range(idx, -1, -1):
            while stack and stack[-1] < nums[i]:
                stack.pop()
            stack.append(nums[i])
        for i in range(len(nums) - 1, -1, -1):
            while stack and stack[-1] <= nums[i]:
                stack.pop()
            if stack:
                res[i] = stack[-1]
            else:
                res[i] = -1
            stack.append(nums[i])
        return res
```