```
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
        self.queue.append(x)
            
    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        k = self.queue.pop()
        return k

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.queue[-1]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if len(self.queue) == 0:
            return True
        else:
            return False
```

