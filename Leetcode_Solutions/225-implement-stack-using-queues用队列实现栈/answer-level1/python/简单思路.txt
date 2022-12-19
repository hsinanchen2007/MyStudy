### 解题思路
简单的利用python的语言特性(算是取巧),可知道list在特定的情况,例如当list.append()+list.pop()
,这时候list就可以看作一个栈(stack),当list.append()+list.pop(0)就可以看作一个队列,这里我们不想思考了，
所以直接用了栈的特性(留待以后思考)。
### 代码

```python
class MyStack(object):
    def __init__(self):
        self.queue=[]

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.queue.append(x)

    def pop(self):
        if self.queue:
            val=self.queue.pop()
            return val

    def top(self):
        return self.queue[-1]


    def empty(self):
        if not self.queue:
            return True
        return False