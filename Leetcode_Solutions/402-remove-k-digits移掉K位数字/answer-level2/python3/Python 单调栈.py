### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        nums = list(num)
        stack = []
        for num in nums:
            while stack and num < stack[-1] and k > 0:
                k -= 1
                stack.pop()
            stack.append(num)
        while k > 0:
            stack.pop()
            k -= 1
        res = ''.join(stack).lstrip('0')
        return res if res != '' else '0'
```