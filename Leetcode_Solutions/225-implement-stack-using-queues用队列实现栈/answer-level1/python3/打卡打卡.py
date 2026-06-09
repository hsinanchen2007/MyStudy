### 解题思路
题解区已经接近四千了，我觉得这种方式不利于社区的质量...
这样跟CSDN那些水文怪有什么区别
### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.data.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        a = self.data[-1]
        del self.data[-1]
        return a


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.data[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if len(self.data) == 0:
            return True
        else:
            return False




# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```