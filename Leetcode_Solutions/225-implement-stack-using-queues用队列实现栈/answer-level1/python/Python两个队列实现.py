### 解题思路
用两个队列维护即可
### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.A = []
        self.B = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.A.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.A) > 1:
            self.B.append(self.A.pop(0))
        rev = self.A.pop()
        self.A, self.B = self.B, self.A
        return rev

    def top(self) -> int:
        """
        Get the top element.
        """
        while len(self.A) > 1:
            self.B.append(self.A.pop(0))
        rev = self.A.pop()
        self.B.append(rev)
        self.A, self.B = self.B, self.A
        return rev


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not bool(self.A)



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```