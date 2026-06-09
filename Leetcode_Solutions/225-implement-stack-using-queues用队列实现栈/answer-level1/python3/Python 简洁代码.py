用两个队列实现栈更为高效。其中两个队列一个是data队列用于主要的数据操作，另一个help队列用于辅助操作。其中入栈操作等价于对data队列的入队操作，出栈操作在于获取data队列的最后一个元素，并维持其他数据有序性。所以我们可以在出栈操作过程中，对data队列中的除最后一个元素之外的进行出队操作，并将元素入队到temp队列中。最后将data与temp互换即可。
代码如下：
```python
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = []
        self.temp = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.data.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.data) > 1:
            self.temp.append(self.data.pop(0))
        self.data, self.temp = self.temp, self.data
        return self.temp.pop(0)


    def top(self) -> int:
        """
        Get the top element.
        """
        temp = self.pop()
        self.push(temp)
        return temp


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.data



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```