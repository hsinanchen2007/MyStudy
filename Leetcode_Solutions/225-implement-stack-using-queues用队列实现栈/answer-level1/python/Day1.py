### 解题思路

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = list()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        tem = self.queue[-1]
        self.queue.pop()
        return tem

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.queue[-1]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not bool(self.queue)



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```