### 解题思路
此处撰写解题思路

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1=[]
        self.queue2=[]


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        if len(self.queue2)==1:
            self.queue1.append(self.queue2.pop(0))
        self.queue1.append(x)
        

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        if len(self.queue2)==0:
            while len(self.queue1)>1:
                self.queue2.append(self.queue1.pop(0))
            temp=self.queue1
            self.queue1=self.queue2
            self.queue2=temp
        return self.queue2.pop(0)


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        if len(self.queue2)==0:
            while len(self.queue1)>1:
                self.queue2.append(self.queue1.pop(0))
            temp=self.queue1
            self.queue1=self.queue2
            self.queue2=temp
        return self.queue2[0]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.queue1)+len(self.queue2)==0
        
# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```