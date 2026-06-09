### Python使用list和deque实现栈
1. Python的list默认可以作为栈(append/pop)使用, 不过通过改变pop的index也可简单作为队列使用, 因此满足题意。
2. Python的deque双端队列本身就支持栈(append/pop或者appendleft/popleft)和队列(append/popleft或者appendleft/pop)的操作, 因此也满足题意。

### 代码1 list实现

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.list = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.list.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.list.pop()


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.list[-1]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.list) == 0

```

### 代码2 deque实现

```python
from collections import deque

class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.deque = deque()


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.deque.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.deque.pop()


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.deque[-1]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.deque) == 0

```