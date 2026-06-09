### 解题思路
第一次写解题思路，献给打卡。基于Python List的栈，很简单的实现。
```
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._queue=[]


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self._queue.append(x)



    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self._queue.pop(-1)


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self._queue[-1]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return not bool(self._queue)
```

