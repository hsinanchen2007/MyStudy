### 解题思路
    按照官方题解，用两个队列代替栈，并参考评论大佬，pyhton实现，。打卡打卡！！！
```
from collections import deque

class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = deque()
        self.q2 = deque()

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q1.append(x) 
        return None
    
    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        res = self.q1.popleft()
        self.q1 , self.q2 = self.q2 , self.q1
        return res

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        res = self.q1.popleft()
        self.q1 , self.q2 = self.q2 , self.q1
        self.q1.append(res)
        return res

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.q1) == 0

```
祝大家都找到自己心仪的Offer



