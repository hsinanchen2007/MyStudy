### 解题思路
不太熟悉单调递增栈，感觉写起来还是挺难的。

### 注意事项
1. 压入栈的是index而不是数值。
2. 判断符合条件时，记得要出栈操作的，每次都忘记。
3. 循环数组的操作可以用i = 2*len(nums) % len(nums)来实现。

### 代码

```python3
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:

        stack = []
        res = [-1] * len(nums)

        for idx, num in enumerate(nums+nums):
            i = idx % len(nums)
            while stack and nums[stack[-1]] < nums[i]:
                res[stack.pop()] = nums[i]
            stack.append(i)
        
        return res
        
```