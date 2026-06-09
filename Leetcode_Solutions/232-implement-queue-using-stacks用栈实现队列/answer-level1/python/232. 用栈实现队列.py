
- list.pop() / list.pop(1) 指定位置pop出去元素
- list.append()

```
class MyQueue(object):
  
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.Queue = []

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: None
        """
        self.Queue.append(x)
        return self.Queue
        
    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """     
        return self.Queue.pop(0)

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        return self.Queue[0]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return len(self.Queue) == 0

```
