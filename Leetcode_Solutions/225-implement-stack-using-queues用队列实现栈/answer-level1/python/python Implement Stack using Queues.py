### 解题思路
此处撰写解题思路

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        if self.queue:
            self.queue = self.queue +[x]
        else:
            self.queue = [x]
        return



    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        x = None
        if self.queue:
            x = self.queue[len(self.queue) - 1]
            self.queue.remove(x)
        return x


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        if self.queue:
            return self.queue[len(self.queue) - 1]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self.queue == []



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```