### 解题思路
1、先将原list排序；
2、用栈的思想，与栈顶相同则出栈；否则入栈；
3、本题已说明只有1个数字出现一次，故返回stack[0]即可。

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        stack = []
        nums.sort()
        for i in range(len(nums)):
            if i == 0:
                stack.append(nums[i])
            if i > 0:
                if nums[i] != nums[i-1]:
                    stack.append(nums[i])
                else:
                    stack.pop()
        return stack[0]
```