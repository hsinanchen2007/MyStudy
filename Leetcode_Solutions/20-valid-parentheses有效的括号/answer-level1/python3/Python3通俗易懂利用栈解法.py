### 解题思路
左右匹配括号, 先进后出, 后进先出, 这个当然要用一个栈来实现最方便!
Python3中利用list的append和pop方法就可以实现栈操作, 写起来很方便.

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0: # 奇数肯定是不匹配的
            return False
        right_2_left = {')': '(', ']': '[', '}': '{'}
        stack = []
        for e in s:
            if e in right_2_left.values():
                stack.append(e)
            else:
                if len(stack) <= 0 or stack.pop() != right_2_left[e]:
                    return False
        if len(stack) != 0:  # 如果没清空stack, 说明括号不匹配的情况存在
            return False
        return True
            
```