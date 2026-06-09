### 解题思路
用内置的list实现一个stack，最关键的地方在于pop功能的实现。
pop首先是要找到stack最近入栈的元素，即stack[-1]
其次还需要将这个元素剔除，其实python3中的list可以调用list.pop(-1)的功能
但这样一来写这个题就没有意义了，所以还是需要自己想办法去实现这个功能
我的解法是切片赋值，即stack[:] = stack[:-1]
就是说stack序列除去最后一个元素后，赋值给新的stack序列

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if len(self.stack):
            p = self.stack[-1]
            self.stack[:] = self.stack[:-1]
            return p

    def top(self) -> int:
        """
        Get the top element.
        """
        if len(self.stack):
            return self.stack[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return False if len(self.stack) else True


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```