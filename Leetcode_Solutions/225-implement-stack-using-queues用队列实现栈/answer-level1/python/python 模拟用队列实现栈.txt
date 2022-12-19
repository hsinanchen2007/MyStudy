### 解题思路
模拟用两个队列结构实现栈，q1和q2是两个队列(python使用pop(0)来模拟弹出首元素过程)。
push操作，入栈元素依次进入q1。
pop操作，将q1中首元素依次进入队列q2，直到剩下最后一个元素，弹出为结果，再将q2复制道q1，q2清空。
top操作，过程类似pop，只是不删除最后一个元素。
empty操作，判断q1长度是否为0即可。
### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = []
        self.q2 = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q1.append(x)
        stack = self.q1
        return stack


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        l = len(self.q1)
        for i in range(0,l-1):
            tmp = self.q1.pop(0)
            self.q2.append(tmp)
        res = self.q1.pop()
        self.q1 = self.q2
        self.q2 = []
        return res
        

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        l = len(self.q1)
        for i in range(0,l-1):
            tmp = self.q1.pop(0)
            self.q2.append(tmp)
        res = self.q1.pop(0)
        self.q2.append(res)
        self.q1 = self.q2
        self.q2 = []
        return res


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        l = len(self.q1)
        if l==0:
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