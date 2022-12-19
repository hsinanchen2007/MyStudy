### 解题思路
不太聪明的样子

### 代码

```python
from collections import deque

class MyStack(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack1 = []
        self.stack2 = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.stack1.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        tmp = None
        if self.stack1:
            while len(self.stack1) > 1:
                self.stack2.append(self.stack1[0])
                self.stack1 = self.stack1[1:]   
            tmp = self.stack1[0]
            self.stack1 = []
        else:
            while len(self.stack2) > 1:
                self.stack1.append(self.stack2[0])
                self.stack2 = self.stack2[1:]
            tmp = self.stack2[0]
            self.stack2 = []
        return tmp

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        res = self.pop()
        self.push(res)
        return res        


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if not self.stack1 and not self.stack2:
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