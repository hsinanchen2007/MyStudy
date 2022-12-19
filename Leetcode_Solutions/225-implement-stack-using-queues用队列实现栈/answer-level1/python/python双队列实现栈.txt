### 解题思路
此处撰写解题思路

### 代码
```python 双队列实现栈 
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.quque1=[]
        self.quque2=[]


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.quque1.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        while len(self.quque1)>1:
            self.quque2.append(self.quque1.pop(0))
        pop_e=self.quque1.pop(0)
        self.quque1,self.quque2=self.quque2,self.quque1
        return pop_e
    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        top_e=self.pop()
        self.push(top_e)
        return top_e



    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return not len(self.quque1)


```
