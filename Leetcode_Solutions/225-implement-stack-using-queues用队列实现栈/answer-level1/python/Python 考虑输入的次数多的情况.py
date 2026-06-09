### 解题思路

两个队列，分别命名为 queue1，queue2。第一个队列只管接受插入。

1. push：append一个值到queue1，并更新一次这个栈的深度（size）。
2. pop：将queue1的（0~size-1）的值，全部后插（append）导入queue2中，直到queue1中只剩一个值的时候，将queue1唯一的值pop出来。再将queue2全部导回到queue1中。
3. top：与pop相同，只不过取出来之后，不pop出来，将其继续插入queue2后，再将queue2全部导回到queue1中。

### 代码

```python
class MyStack(object):

    def __init__(self):
        self.queue1 = []
        self.queue2 = []
        self.size = 0

    def push(self, x):
        self.size += 1
        self.queue1.append(x)

    def pop(self):
        if self.size <= 0:
            return None
        self.size -= 1
        for i in range(self.size):
            self.queue2.append(self.queue1.pop(0))
        temp = self.queue1.pop(0)
        for i in range(self.size):
            self.queue1.append(self.queue2.pop(0))
        return temp
    def top(self):
        if self.size <= 0:
            return None
        for i in range(self.size - 1):
            self.queue2.append(self.queue1.pop(0))
        temp = self.queue1.pop(0)
        self.queue2.append(temp)
        for i in range(self.size):
            self.queue1.append(self.queue2.pop(0))
        return temp
    def empty(self):
        return not self.size
```