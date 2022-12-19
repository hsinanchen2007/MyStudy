### 解题思路
用栈解决即可，其中关于栈的定义需要注意pop和top操作需要对栈进行判空。

### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = Stack()
        my_dict = {
            '(': ')',
            '{': '}',
            '[': ']'
        }
        for ch in s:
            if ch in my_dict:
                stack.push(ch)
            else:
                if not stack.is_empty() and ch == my_dict[stack.top()]:
                    stack.pop()
                else:
                    return False
        if not stack.is_empty():
            return False
        return True

class Stack(object):
    def __init__(self):
        self.stack = []

    def push(self, val):
        self.stack.append(val)

    def pop(self):
        if self.is_empty():
            raise Exception('stack is empty!')
        del self.stack[-1]

    def is_empty(self):
        return True if len(self.stack) == 0 else False

    def top(self):
        if self.is_empty():
            raise Exception('stack is empty!')
        return self.stack[-1] 
```