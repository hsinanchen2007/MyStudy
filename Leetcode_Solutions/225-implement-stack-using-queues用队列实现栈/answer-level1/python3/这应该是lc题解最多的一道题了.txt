### 解题思路
这应该是lc题解最多的一道题了，两个双端队列模拟入栈。

### 代码

```python3
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        from collections import deque
        self.l = deque()
        self.temp = deque()

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        while self.l:
            self.temp.append(self.l.popleft())
        self.l.append(x)
        while self.temp:
            self.l.append(self.temp.popleft())
        

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.l.popleft()

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.l[0]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return not bool(self.l)
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```