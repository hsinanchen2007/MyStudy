### 解题思路
两个队列，进队直接压入， 出栈转一圈，inqueue出队列到outqueue直到只剩最后一个数值，进行操作后,再把outqueue压入inqueue

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.inqueue = []
        self.outqueue = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.inqueue.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.inqueue) != 1:
            self.outqueue.append(self.inqueue.pop(0))
        ans = self.inqueue.pop()
        while self.outqueue != []:
            self.inqueue.append(self.outqueue.pop(0))
        return ans

    def top(self) -> int:
        """
        Get the top element.
        """
        while len(self.inqueue) != 1:
            self.outqueue.append(self.inqueue.pop(0))
        ans = self.inqueue.pop()
        while self.outqueue != []:
            self.inqueue.append(self.outqueue.pop(0))
        self.inqueue.append(ans)
        return ans

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if self.inqueue == []:
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