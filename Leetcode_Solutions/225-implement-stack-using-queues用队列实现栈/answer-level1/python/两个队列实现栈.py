### 解题思路
此处撰写解题思路
栈是先进后出，队列是先进先出
栈每次只出栈顶一个元素
我建立q1,q2两个列表
q1[0]用于存栈顶元素
q2用于存剩下的元素
因此下边的循环每次将q1栈顶之外的元素存到q2里去
while len(self.q1)>1:
            self.q2.append(self.q1[0])
            self.q1=self.q1[1:]

出栈将栈顶赋给top 清空q2
再通过上边的循环将q1栈顶之外的元素给q2
这就构成了push pop top empty....

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1=[]
        self.q2=[]


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q1.append(x)
        while len(self.q1)>1:
            self.q2.append(self.q1[0])
            self.q1=self.q1[1:]
        


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        top = self.q1[0]
        self.q1,self.q2 = self.q2,[]
        while len(self.q1)>1:
            self.q2.append(self.q1[0])
            self.q1=self.q1[1:]
        return top

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.q1[0]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return not self.q1 and not self.q2


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```