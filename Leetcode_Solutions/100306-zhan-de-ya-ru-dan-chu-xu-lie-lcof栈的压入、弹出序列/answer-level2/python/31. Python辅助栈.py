### 解题思路
这道题最直观的想法就是利用辅助栈，模拟一遍出栈序列即可。

### 代码

```python
class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        length = len(pushed)
        if length == 0:
            return True
        stack = []
        p = q = 0
        while p < length or q < length:
            if len(stack) == 0 or popped[q] != stack[-1]:
                if p < length:
                    stack.append(pushed[p])
                    p += 1
                else:
                    return False
            else:
                del stack[-1]
                q += 1
        return True
```