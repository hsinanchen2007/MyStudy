### 解题思路
pop完后再依次append

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack=[]
        self.length=0

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.stack.append(x)
        self.length+=1

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        q=[]
        for i in range(self.length-1):
            q.append(self.stack.pop(0))
        element=self.stack.pop(0)
        for i in range(self.length-1):
            self.stack.append(q[i])
        self.length-=1
        return element


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.stack[-1]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self.length==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```