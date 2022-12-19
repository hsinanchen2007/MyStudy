```
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = collections.deque()

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.data.append(x)
        for i in range(len(self.data)-1):
            self.data.append(self.data.popleft())

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.data.popleft()
    
    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.data[0]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return not len(self.data)
```
