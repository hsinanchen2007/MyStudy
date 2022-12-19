### 解题思路
Python的list即为栈。

### 代码

```python
class MyStack:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.s = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.s.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.s.pop()


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.s[-1]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.s

```