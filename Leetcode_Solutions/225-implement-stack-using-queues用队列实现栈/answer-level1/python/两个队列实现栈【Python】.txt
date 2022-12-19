### 解题思路
这里需要注意的就是弄清楚辅助栈和数据栈里面数据的存储，并且注意每次进行pop和top操作都需要把辅助栈的元素重新放回数据栈

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
        self.queue1.append(x)



    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        if self.queue1:
            while len(self.queue1) > 1: 
                self.queue2.append(self.queue1.pop(0)) 
            res=self.queue1.pop(0)
            while self.queue2:
                self.queue1.append(self.queue2.pop(0))
            return res
        else:
            return False

      



    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        if self.queue1:
            while len(self.queue1) > 1: 
                self.queue2.append(self.queue1.pop(0))
            res=self.queue1.pop(0)
            self.queue2.append(res)
            while self.queue2:
                self.queue1.append(self.queue2.pop(0))
            return res
        else:
            return False
       
       


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.queue1)==0 and len(self.queue2)==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```