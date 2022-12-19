```python
class MyStack:

    def __init__(self):
        self.q = collections.deque()

    def push(self, x):
        self.q.append(x)
        for _ in range(len(self.q) - 1): self.q.append(self.q.popleft())
        
    def pop(self):
        return self.q.popleft()

    def top(self):
        return self.q[0]
    
    def empty(self):
        return not len(self.q)
```
- push 的时候把 x 放入队尾，然后遍历一遍原始队列元素，每次弹出之后加入队尾
```python
from queue import Queue

class MyStack:

    def __init__(self):
        self.q = Queue()

    def push(self, x):
        self.q.put(x)
        for _ in range(self.q.qsize() - 1): self.q.put(self.q.get())
        
    def pop(self):
        return self.q.get()

    def top(self):
        r = self.q.get()
        self.q.put(r)
        for _ in range(self.q.qsize() - 1):
            self.q.put(self.q.get())
        return r
    
    def empty(self):
        return not self.q.qsize()
```
- Queue模式