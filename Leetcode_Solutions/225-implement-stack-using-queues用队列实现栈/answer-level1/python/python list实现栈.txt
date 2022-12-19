### 解题思路
粗暴地把队列最后作为了栈顶。
push就对应了append操作；
pop使用del实现；
top就取列表中的最后一个元素；
empty返回列表长度是否为零。

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        #l = len(self.stack)
        self.stack.append(x)



    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        l = len(self.stack)
        item = self.stack[l-1]
        del(self.stack[l-1])
        return item


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        l = len(self.stack)
        item = self.stack[l-1]
        return item



    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        l = len(self.stack)
        return l==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```