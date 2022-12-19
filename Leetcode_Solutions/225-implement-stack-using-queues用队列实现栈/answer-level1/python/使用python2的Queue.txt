### 解题思路
队列与栈不同在于一个先进先出，一个后进先出，所以为了使队列完成后进先出，只需在压入元素到队列之后将队列前的n-1个元素移入到该元素之后即可

### 代码

```python
from Queue import Queue  #此处需注意python3为 from queue import Queue

class MyStack(object):

    def __init__(self):
        self.q = Queue()

    def push(self, x):
        self.q.put(x)
        for _ in range(self.q.qsize()-1):
            tmp = self.q.get()
            self.q.put(tmp)

    def pop(self):
        return self.q.get()

    def top(self):
        ttmp = self.q.get()
        self.q.put(ttmp)
        for _ in range(self.q.qsize()-1):
            tmp = self.q.get()
            self.q.put(tmp)
        return ttmp

    def empty(self):
        return self.q.empty()

```