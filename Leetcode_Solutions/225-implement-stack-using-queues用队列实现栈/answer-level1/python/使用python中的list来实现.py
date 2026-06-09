### 解题思路
此处撰写解题思路
选择python来实现，在python中没有队列这个概念，因此借用list来实现
初始化：创建一个list
push：入栈就是将元素放入到栈顶，在list中也就是将元素加入到list尾
pop：调用list的方法pop获取元素
top：获取list的最后一个元素
empty：判断list是否为空
### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        s=[]
        self.stack = s


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.stack.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        value = self.stack.pop()
        return value



    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        l = len(self.stack)
        return self.stack[l-1]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if len(self.stack) == 0:
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