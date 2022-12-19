### 解题思路
用两个队列实现栈

### 代码

```python
from collections import deque
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1 = deque([])
        self.queue2 = deque([])


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.queue1.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        if self.empty():
            return None
        # if not empty
        if self.queue1:
            res = self.queue1.popleft()
            while self.queue1:
                self.queue2.append(res)
                res = self.queue1.popleft()
            return res
        elif self.queue2:
            res = self.queue2.popleft()
            while self.queue2:
                self.queue1.append(res)
                res = self.queue2.popleft()
            return res

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        if self.queue1:
            return self.queue1[-1]
        return self.queue2[-1]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if self.queue1 or self.queue2:
            return False
        return True



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```