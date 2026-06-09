## 思路：

数据规模 ，时间复杂度$O(n^2)$上都过不了，这道题用的是**单调栈**

倒着遍历数组，维护单调减栈，当来数字大于栈顶，弹出栈顶赋予`ak`，相当于找到次大值，如果出现比次大小数，返回`true`

## 代码：

```python
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        ak = float("-inf")
        stack = []
        for num in reversed(nums):
            if ak > num: return True
            while stack and stack[-1] < num:
                ak = stack.pop()
            stack.append(num)
        return False
```

