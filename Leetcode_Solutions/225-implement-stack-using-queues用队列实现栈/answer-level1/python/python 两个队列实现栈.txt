### 解题思路
队列有put()、get()方法，对应先进先出。进栈和进队列一样，但是出栈出的是栈尾元素，队列实现需要将队列前部的元素出队列暂存到另一个队列，从而得到该队列尾部元素，取出后，再把暂存另一个队列的元素取回放到原队列。当然，看代码最直接了！

### 代码

```python
import Queue as q
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        
        self.q1=q.Queue()
        self.q2=q.Queue()

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q1.put(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        while self.q1.qsize()>1:
            self.q2.put(self.q1.get())
        tmp=self.q1.get()
        self.q1,self.q2=self.q2,self.q1
        return tmp

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        tmp=self.pop()
        self.q1.put(tmp)
        return tmp



    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self.q1.empty() and self.q2.empty()



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```