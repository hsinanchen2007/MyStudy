### 解题思路
使用两个队列，除了栈为空时，两个队列可以同时为空。其他时间保证一个队列非空、一个队列为空

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1 = []
        self.queue2 = []

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        if self.queue2 and not self.queue1:
            self.queue2.append(x)
        else:
            self.queue1.append(x)
        


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        if not self.queue1 and not self.queue2:
            return None
        
        while self.queue1:
            value = self.queue1.pop(0)
            if not self.queue1:
                return value
            
            self.queue2.append(value)
        
        while self.queue2:
            value = self.queue2.pop(0)
            if not self.queue2:
                return value
            self.queue1.append(value)


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        if not self.queue1 and not self.queue2:
            return None
        while self.queue1:
            value = self.queue1.pop(0)
            self.queue2.append(value)
            if not self.queue1:
                return value

        while self.queue2:
            value = self.queue2.pop(0)
            self.queue1.append(value)
            if not self.queue2:
                return value


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if not self.queue1 and not self.queue2:
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